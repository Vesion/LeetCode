#include <thread>
#include <condition_variable>
#include <mutex>
#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory>

// A thread is waiting for another tread to complete something

// the most naive way, brute checking a shared flag
bool flag;
std::mutex flag_m;

void wait_for_flag() {
  std::unique_lock<std::mutex> lock(flag_m);
  while (!flag) {  // silly consumes resource
    lock.unlock();
    // only by this chance another thread could acquire lock and set flag
    lock.lock();
  }
  // start do something
}

// periodically check a shared flag
void wait_for_flag_p() {
  std::unique_lock<std::mutex> lock(flag_m);
  while (!flag) {  // silly consumes resource
    lock.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));// only by this chance another thread could acquire lock and set flag
    lock.lock();
  }
  // start do something
}

// condition variable
// A condition variable is associated with some event or other condition, one or more threads can
// wait for that condition to be satisfied.
// When some thread has determined that the condition is satisfied, it can then notify one or more
// of the threads waiting on the condition variable, in order to wake them up and allow them to
// continue processing.
std::queue<int> data;
int data_i;
std::mutex data_m;
std::condition_variable data_cond;

void prepare_data_for_one() {
  while (true) {  // continuously producing data
    std::lock_guard<std::mutex> lock(data_m);  // lock to protect data
    data.push(data_i++);
    data_cond.notify_one();  // notify one waiting thread
  }
}

// actually this is not a suitable example for notify_all,
// it's more likely that waiting threads are processing the same data
void prepare_data_for_all() {
  while (true) {
    std::lock_guard<std::mutex> lock(data_m);
    data.push(data_i++);
    data_cond.notify_all();  // notify all waiting threads
  }
}

void process_data() {
  while (true) {  // continuously consuming data
    std::unique_lock<std::mutex> lock(data_m);  // lock at first
    // firstly, wait() checks if cond is satisfied,
    // if cond is satisfied, returns directly with lock acquired untouch
    // if cond is not satisfied, wait() unlocks the mutex and puts the thread in a blocked/waiting state,
    // when the condition variable is notified, the thread wakes, then acuqires lock and checks the cond again,
    // if cond is satisfied, returns with lock acquired,
    // if cond is not satisfied, unlocks and resumes waiting.
    data_cond.wait(lock, [](){ return !data.empty(); });
    int i = data.front();  // do not process data here with locked mutex, because it could be a time-consuming operation
    data.pop();
    lock.unlock();
    std::cout << i << std::endl;  // do processing here after unlock
  }
}

int main () {
  {
    std::thread t1(prepare_data_for_one);
    std::thread t2(process_data);
    t1.join();
    t2.join();
  }

  // {
  //   std::thread t1(prepare_data_for_all);
  //   std::thread t2(process_data), t3(process_data), t4(process_data);
  //   t1.join();
  //   t2.join(); t3.join(); t4.join();
  // }
}