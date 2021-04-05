#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class MyCircularQueue {
    vector<int> q;
    int begin, end;
    int size;
public:
    MyCircularQueue(int k) {
        q.resize(k);
        begin = 0, end = 0;
        size = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        q[end] = value;
        end = end+1 == q.size() ? 0 : end+1;
        ++size;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        begin = begin+1 == q.size() ? 0 : begin+1;
        --size;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return q[begin];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return q[end == 0 ? q.size()-1 : end-1];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == q.size();
    }
};


int main() {
}
