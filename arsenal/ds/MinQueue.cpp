#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
#include <stack> 
using namespace std;

// MinQueue is a queue (adapter) which supports push, front, pop, as well as min (return the minimal element in queue)
// Note: it is different with priority_queue, MinQueue must ensure first-in-fir-out


// Solution 1 : implement with queue and deque
// All above operations, except for push, take O(1) time, push takes O(n) time
class MinQueue_1 {
private:
    queue<int> eq;
    deque<int> mq;
public:
    void push(int x) {
        eq.push(x);
        while (!mq.empty() && x < mq.back()) mq.pop_back();
        mq.push_back(x);
    }

    void pop() {
        if (eq.front() == mq.front()) mq.pop_front();
        eq.pop();
    }

    int front() { return eq.front(); }
    int min() { return mq.front(); }
    bool empty() { return eq.empty(); }
};


// Solution 2 : implement with two MinStack (same with implementing queue with stack)
// All above operations take amortized O(1) time
// http://www.keithschwarz.com/interesting/code/?dir=min-queue
class MinStack {
    stack<int> es, ms;
public:
    void push(int x) { es.push(x); if (ms.empty() || x <= ms.top()) ms.push(x); }
    void pop() { if (es.top() == ms.top()) ms.pop(); es.pop(); }
    int top() { return es.top(); }
    int min() { return ms.top(); }
    bool empty() { return es.empty(); }
};

class MinQueue {
private:
    MinStack olds, news;
    void MoveNewToOld() {
        if (!olds.empty()) return;
        while (!news.empty()) {
            olds.push(news.top());
            news.pop();
        }
    }

public:
    void push(int x) { 
        news.push(x);
    }

    void pop() {
        MoveNewToOld();
        olds.pop();
    }

    int front() { 
        MoveNewToOld();
        return olds.top();
    }

    int min() { 
        if (!olds.empty() && !news.empty()) return std::min(olds.min(), news.min());
        if (!olds.empty()) return olds.min();
        return news.min();
    }

    bool empty() { 
        return olds.empty() && news.empty(); 
    }
};

int main() {
    vector<int> nums = {0, 6, 5, 3, 2, 4, 1};    
    MinQueue_1 q1;
    for (auto n : nums) {
        q1.push(n);
        cout << q1.min() << ' ';
    }
    cout <<endl;
    while (!q1.empty()) {
        cout << q1.min() << ' ';
        q1.pop();
    }
    cout <<endl;

    MinQueue q;
    for (auto n : nums) {
        q.push(n);
        cout << q.min() << ' ';
    }
    cout <<endl;
    while (!q.empty()) {
        cout << q.min() << ' ';
        q.pop();
    }
    cout <<endl;
    return 0;
}

