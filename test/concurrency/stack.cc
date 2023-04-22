#include <thread>
#include <mutex>
#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stack>

template <typename T>
class ThreadsafeStack {
 public:
  ThreadsafeStack() = default;
  ~ThreadsafeStack() = default;

  ThreadsafeStack(const ThreadsafeStack& rhs) {
    std::lock_guard<std::mutex> locK(rhs.m_);  // note lock rhs's mutex
    data_ = rhs.data_;
  }
  ThreadsafeStack& operator=(const ThreadsafeStack&) = delete;

  bool empty() const {
    std::lock_guard<std::mutex> lock(m_);
    return data_.empty();
  }

  void push(const T& t) {
    std::lock_guard<std::mutex> lock(m_);
    data_.push(t);
  }

  // How to be thread safe?
  // 1. Combine top() and pop() into one method pop();
  // 2. Let pop() throw exception if data is empty();
  // 3. Do not return by value in case of the copy ctor of T fails.

  // receive result through passing a reference argument
  void pop(T& result) {
    std::lock_guard<std::mutex> lock(m_);
    if (data_.empty()) throw std::exception();  // check empty again, in case of race condition
    result = data_.top();  // copy before return, in case invariant broken if copy fails
    data_.pop();
  }

  // return a pointer to the popped item
  std::shared_ptr<T> pop() {
    std::lock_guard<std::mutex> lock(m_);
    if (data_.empty()) throw std::exception();  // check empty again, in case of race condition
    auto result = std::make_shared<T>(data_.top());  // copy before return, in case invariant broken if copy fails
    data_.pop();
    return result;
  }

 private:
  std::stack<T> data_;
  mutable std::mutex m_;
};

template <typename T>
class lock_free_stack {
 private:
  struct Node {
    std::shared_ptr<T> value;  // use std::shared_ptr<T> to avoid throwing exception when pop()
    Node* next;
    Node(const T& v) : value(std::make_shared<T>(v)) {}
  };

  std::atomic<Node*> head_;

  std::atomic<int> pop_threads_;  // count how many threads are poping concurrently right now
  std::atomic<Node*> to_be_deleted_;  // list of nodes to be deleted

  void delete_nodes(Node* nodes) {
    while (nodes) {
      Node* next = nodes->next;
      delete nodes;
      nodes = next;
    }
  }

  void chain_pending_nodes(Node* nodes) {
    Node* last = nodes;
    while (last->next) {
      last = last->next;
    }
    chain_pending_nodes(nodes, last);
  }

  void chain_pending_node(Node* node) {
    chain_pending_nodes(node, node);
  }

  void chain_pending_nodes(Node* first, Node* last) {
    last->next = to_be_deleted_;
    while (!to_be_deleted_.compare_exchange_weak(last->next, first));
  }

  // this could work for low-load situations, for high-load situation we need harzard-pointers/reference-counting
  void try_reclaim(Node* old_head) {
    if (pop_threads_ == 1) {  // this thread is the only one thread in pop()
      // claim could-be-deleted nodes which were chained before by other threads,
      // but during this period, it's opportunity for other threads to preempt and increment pop_threads_
      Node* nodes_to_delete = to_be_deleted_.exchange(nullptr);
      // so after claiming we must test pop_threads_ again to make sure no other threads are
      // accessing nodes in nodes_to_delete before deleting them
      if (--pop_threads_ == 0) {  // if 0, no other threads are accessing nodes in nodes_to_delete
        delete_nodes(nodes_to_delete);
      } else if (nodes_to_delete) {  // not safe to delete, chain them back
        chain_pending_nodes(nodes_to_delete);
      }
      // deleting is time-consuming, so put it at the end to make the window
      // between when the thread first finds threads_in_pop to be equal to 1 and the attempt to delete the nodes as small as possible
      delete old_head;
    } else {  // not safe to delete any node, chain it
      chain_pending_node(old_head);
      --pop_threads_;
    }
  }

 public:
  void push(const T& value) {
    Node* new_node = new Node(value);
    new_node->next = head_.load();
    while (!head_.compare_exchange_weak(new_node->next, new_node));  // theoretically could be endless loop if compare_exchange_weak keeps failing
  }

  std::shared_ptr<T> pop(T& value) {
    ++pop_threads_;
    Node* old_head = head_.load();
    while (old_head && !head_.compare_exchange_weak(old_head, old_head->next));  // theoretically could be endless loop if compare_exchange_weak keeps failing
    std::shared_ptr<T> res;
    if (old_head) {
      res.swap(old_head->value);
    }
    try_reclaim(old_head);
    return res;
  }
};

int main() {
  ThreadsafeStack<int> st;
  st.push(10);
  auto f3 = [&st]() {
    if (!st.empty()) {
      int i;
      st.pop(i);  // Could throw exception, so ideally need a try-catch
      std::cout << i << std::endl;
    }
  };
  std::thread t3(f3);
  std::thread t4(f3);
  t3.join();
  t4.join();

  std::cout << "main thread exits" << std::endl;
  return 0;
}