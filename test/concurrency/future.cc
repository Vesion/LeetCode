#include <thread>
#include <condition_variable>
#include <mutex>
#include <cassert>
#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory>

// If the waiting thread is going to wait only once, so when the condition is true it will
// never wait on this condition variable again, a condition variable might not be the best
// choice of synchronization mechanisms.
// In this scenario (waiting for an one-off event), a future might be more appropriate.
// A valid() future references to a shared state.

int slow_get_1() {
  std::this_thread::sleep_for(std::chrono::milliseconds(2));
  return 1;
}

void slow_get_2(std::promise<int> promise) {
  std::this_thread::sleep_for(std::chrono::milliseconds(2));
  promise.set_value(2);
}

int main() {
  // 1. create future by std::async
{
  std::future<int> result = std::async(slow_get_1);  // maybe start an asynchronous task (new thread)
  std::cout << "async result is : ";  // do other stuff
  std::cout << result.get() << std::endl;  // block and wait until the future is ready
  std::cout << "is result valid: " << result.valid() << std::endl;  // right after the first calling get(), the future is not valid any more

  std::future<int> r1 = std::async(std::launch::async, slow_get_1);  // enforce start a new thread
  std::future<int> r2 = std::async(std::launch::deferred, slow_get_1);  // the function call is deferred until wait/get is called
  std::future<int> r3 = std::async(std::launch::async | std::launch::deferred, slow_get_1);  // implementation choose, default
  std::cout << r1.get() << std::endl;  // block and wait until the future is ready
  std::cout << r2.get() << std::endl;  // call slow_get_1()
  std::cout << r3.get() << std::endl;  // either above might happen
}

  // 2. create future by std::packaged_task
  // a wrapper to associate a task with a future
{
  std::packaged_task<int()> task(slow_get_1);
  std::future<int> result = task.get_future();  // associate the future with a promised result (shared state)
  std::packaged_task<int()> moved_task = std::move(task);  // no matter where the task is moved to
  std::thread t(std::ref(moved_task));  // should std::ref since std::packaged_task is not copyable!
  t.detach();
  std::cout << "packaged_task result is : " << result.get() << std::endl;
  // t.join();  // whichever (detach or join) is OK since we only care about the future
}

  // 3. create future by std::promise
{
  std::promise<int> promise;
  std::future<int> result = promise.get_future();  // associate the future with a promised result (shared state)
  std::thread t(slow_get_2, std::move(promise));  // although the promise is moved, the shared state is still referenced by both moved promise and the future
  std::cout << "promise result is : " << result.get() << std::endl;  // block current thread until promise sets value
  t.join();
}

  // 4. std::shared_future allows multiple objects referring to the same shared state
{
  std::future<int> result = std::async(slow_get_1);
  assert(result.valid());
  std::shared_future<int> r1 = result.share();  // transfer ownership of shared state into r1
  std::shared_future<int> r2 = r1;  // copy a reference to shared state
  assert(!result.valid());
  assert(r1.valid());
  std::cout << "shared promise result r1: " << r1.get() << std::endl;
  assert(r2.valid());  // r1's wait()/get() won't release r2's refenrece, and won't destroy the shared state
  std::cout << "shared promise result r2: " << r2.get() << std::endl;
}

}