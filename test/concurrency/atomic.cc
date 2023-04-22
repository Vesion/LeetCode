#include <thread>
#include <mutex>
#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cassert>
#include <atomic>


// std::atomic_flag
class spinlock_mutex {
  std::atomic_flag flag = ATOMIC_FLAG_INIT;
 public:
  void lock() {
    // A busy-wait, which means the thread consums CPU cycles when it is blocked.
    while (flag.test_and_set(std::memory_order_acquire));
  }

  void unlock() {
    flag.clear(std::memory_order_release);
  }
};

// std::atomic<bool>
void f1() {
  std::atomic<bool> b;
  bool x = b.load(std::memory_order_acquire);  // load() return values rather than references
  b.store(true);
  x = b.exchange(false,std::memory_order_acq_rel);
}

// std::atomic<T*>
void f2() {
  class Foo{};
  Foo some_array[5];
  std::atomic<Foo*> p(some_array);
  Foo* x=p.fetch_add(2);
  assert(x==some_array);
  assert(p.load()==&some_array[2]);
  x=(p-=1);
  assert(x==&some_array[1]);
  assert(p.load()==&some_array[1]);
}

// std::atomic<IntegralType>

// std::atomic<User defiend type>, could be lock-free or not.
// UDT must have a trivial copy-assignment operator,
// UDT must be bitwise equality comparable.


// memory order
// https://gcc.gnu.org/wiki/Atomic/GCCMM/AtomicSync
std::atomic<int> x, y;
int m, n;

// Sequentially Consistent (by default)
// All the visible variables must be flushed through the system so that all threads see the same state
void thread1() {
  y.store(2);  // std::memory_order_seq_cst by default
  x.store(1);  // std::memory_order_seq_cst by default
}
void thread2() {
  if (x.load() == 1) {
    assert(y.load() == 2);  // can not fail
    y.store(1);
  }
}
void thread3() {
  if (y.load() == 1) {
    assert(x.load() == 1);  // can not fail
  }
}


// Relaxed
// There is no synchronization at all, only guarantee atomicity and modification order consistency.
void thread4() {
  // order of these two independent stores is unspecified
  y.store(2, std::memory_order_relaxed);
  x.store(1, std::memory_order_relaxed);
}
void thread5() {
  if (x.load(std::memory_order_relaxed) == 1) {
    assert(y.load(std::memory_order_relaxed) == 2);  // could fail!
    y.store(1, std::memory_order_relaxed);
  }
}
void thread6() {
  if (y.load(std::memory_order_relaxed) == 1) {
    assert(x.load(std::memory_order_relaxed) == 1);  // could fail!
  }
}


// Acquire/Release
// release - no stores can be reordered wrt. the atomic store.
//           I.e. if they are before the atomic store in the source code, they will happen before the atomic store too.
// acquire - no loads can be reordered wrt. the atomic load.
//           I.e. if they are after the atomic load in the source code, they will happen after the atomic load too.
// Only requires the two threads involved to be synchronized
void thread7() {
  y.store(2, std::memory_order_release);
}
void thread8() {
  x.store(1, std::memory_order_release);
}
// if in Sequentially Consistent order, one pass the other must fail
void thread9() {
  assert(y.load(std::memory_order_acquire) == 2 && x.load(std::memory_order_acquire) == 0);  // could pass
}
void thread10() {
  assert(y.load(std::memory_order_acquire) == 0 && x.load(std::memory_order_acquire) == 1);  // could pass
}

void thread11() {
  m = 2;
  x.store(1, std::memory_order_release);
}
void thread12() {
  if (x.load(std::memory_order_acquire) == 1) {
    assert(m == 2);  // coult not fail
  }
}


// Consume
// There may be less hardware synchronization required
// consume - no loads that are dependent on the newly loaded value can be reordered wrt. the atomic load.
//           I.e. if they are after the atomic load in the source code, they will happen after the atomic load too.
std::atomic<int*> p;
void thread13() {
  n = 1;
  m = 1;
  p.store(&n, std::memory_order_release);
}
void thread14() {
  int* t = p.load(std::memory_order_acquire);
  assert(*t == 1 && m == 1);  // could not fail
}
void thread15() {
  int* t = p.load(std::memory_order_consume);
  assert(*t == 1 && m == 1);  // could fail, there is no longer a dependency between the store to p, and the store to m
}


// Fence
void thread16() {
  x.store(1, std::memory_order_relaxed);
  std::atomic_thread_fence(std::memory_order_release);  // as if y.store(std::memory_order_release)
  y.store(1, std::memory_order_relaxed);
}
void thread17() {
  if (y.load(std::memory_order_relaxed)) {
    std::atomic_thread_fence(std::memory_order_acquire);  // as if y.load(std::memory_order_acquire)
    assert(x.load(std::memory_order_relaxed));  // could not fail
  }
}

int main() {
  for (int i = 0; i < 100; ++i) {
    std::thread t16(thread16);
    std::thread t17(thread17);
    t16.join();
    t17.join();
  }
  return 0;
}
