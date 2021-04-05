#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class BoundedBlockingQueue {
    mutex m;
    queue<int> q;
    int cap;
    // need two cvs, consumers should only wake up producers, vice versa
    condition_variable enq_cv, deq_cv;

public:
    BoundedBlockingQueue(int capacity) {
        cap = capacity;
    }

    void enqueue(int element) {
        {
            unique_lock<mutex> lock(m);
            enq_cv.wait(lock, [this](){ return q.size() < cap; });
            q.push(element);
        }
        deq_cv.notify_one();
    }

    int dequeue() {
        int x;
        {
            unique_lock<mutex> lock(m);
            deq_cv.wait(lock, [this](){ return !q.empty(); });
            x = q.front(); q.pop();
        }
        enq_cv.notify_one();
        return x;
    }

    int size() {
        lock_guard<mutex> lock(m);
        return q.size();
    }
};

int main() {
}
