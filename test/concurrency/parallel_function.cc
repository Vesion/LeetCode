#include <thread>
#include <algorithm>
#include <condition_variable>
#include <mutex>
#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory>

template <typename Iterator, typename Func>
void parallel_for_each(Iterator first, Iterator last, Func f) {
  size_t length = std::distance(first, last);
  if (!length) {
    return;
  }

  constexpr size_t min_chunk_size = 16;
  size_t max_threads = (length + min_chunk_size - 1) / min_chunk_size;
  size_t hardware_threads = std::thread::hardware_concurrency();
  size_t num_threads = std::min(hardware_threads ? hardware_threads : 2, max_threads);
  size_t chunk_size = length / num_threads;

  std::vector<std::future<void>> futures(num_threads - 1);
  std::vector<std::thread> extra_threads(num_threads - 1);

  Iterator start = first;
  for (size_t i = 0; i < num_threads - 1; ++i) {
    Iterator end = start;
    std::advance(end, chunk_size);
    std::packaged_task<void(void)> task([&start, &end, &f] { std::for_each(start, end, f); });
    futures[i] = task.get_future();
    extra_threads[i] = std::thread(std::move(task));
    start = end;
  }
  std::for_each(start, last, f);
  for (auto& future : futures) {
    future.get();
  }
  for (auto& thread : extra_threads) {
    thread.join();
  }
}

template <typename Iterator, typename Func>
void parallel_for_each_async(Iterator first, Iterator last, Func f) {
  size_t length = std::distance(first, last);
  if (!length) {
    return;
  }
  constexpr size_t min_chunk_size = 16;
  if (length < 2 * min_chunk_size) {
    std::for_each(first, last, f);
  } else {
    Iterator mid = first + length / 2;
    std::future<void> first_half = std::async(parallel_for_each_async<Iterator, Func>, first, mid, f);
    parallel_for_each_async(mid, last, f);
    first_half.get();  // synchronize
  }
}

template <typename Iterator, typename TargetType>
Iterator parallel_find(Iterator first, Iterator last, const TargetType& target) {
  size_t length = std::distance(first, last);
  if (!length) {
    return last;
  }
  constexpr size_t min_chunk_size = 16;
  size_t max_threads = (length + min_chunk_size - 1) / min_chunk_size;
  size_t hardware_threads = std::thread::hardware_concurrency();
  size_t num_threads = std::min(hardware_threads ? hardware_threads : 2, max_threads);
  size_t chunk_size = length / num_threads;

  std::promise<Iterator> promise;
  std::atomic<bool> done(false);
  std::vector<std::thread> extra_threads(num_threads - 1);

  auto find = [&promise, &done](Iterator begin, Iterator end, const TargetType& target) {
    for (; begin != end && !done; ++begin) {
      if (*begin == target) {
        promise.set_value(begin);
        done = true;
        return;
      }
    }
  };

  Iterator start = first;
  for (size_t i = 0; i < num_threads - 1; ++i) {
    Iterator end = start;
    std::advance(end, chunk_size);
    extra_threads[i] = std::thread(find, start, end, target);
    start = end;
  }
  find(start, last, target);
  for (auto& thread : extra_threads) {
    thread.join();
  }
  if (!done) {
    return last;
  }
  return promise.get_future().get();
}

template <typename Iterator, typename TargetType>
Iterator parallel_find_async(Iterator first, Iterator last, const TargetType& target) {
  std::atomic<bool> done(false);

  std::function<Iterator(Iterator, Iterator, const TargetType&)>
  auto find = [&done, &find](Iterator begin, Iterator end, const TargetType& target) {
    size_t length = std::distance(begin, end);
    constexpr size_t min_chunk_size = 16;
    if (length < min_chunk_size * 2) {
      for (; begin != end && !done; ++begin) {
        if (*begin == target) {
          done = true;
          return begin;
        }
      }
      return end;
    }

    Iterator mid = begin + length / 2;
    Iterator first_half = find(begin, mid, target);
    std::future<Iterator> second_half = std::async(find, mid, end, target);
    if (first_half != mid) {
      return first_half;
    }
    return second_half.get();
  };

  return find(first, last, target);
}

template <typename Iterator>
void parallel_partial_sum(Iterator first, Iterator last) {

}

int main() {
  std::cout << "hardware_concurrency : " << std::thread::hardware_concurrency() << std::endl;
  std::vector<int> a(100);
  for (int i = 0; i < a.size(); ++i) a[i] = i+1;
  parallel_for_each(a.begin(), a.end(), [](int n){ std::cout << n << std::endl; });
  parallel_for_each_async(a.begin(), a.end(), [](int n){ std::cout << n << std::endl; });

  std::cout << std::distance(a.begin(), parallel_find(a.begin(), a.end(), 6)) << std::endl;
  std::cout << *parallel_find_async(a.begin(), a.end(), 6) << std::endl;
  std::cout << std::distance(a.begin(), parallel_find_async(a.begin(), a.end(), 6)) << std::endl;
}
