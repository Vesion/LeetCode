#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class FrontMiddleBackQueue {
    deque<int> left, right;
    void balance() {
        if (right.size() > left.size()+1) {
            left.push_back(right.front());
            right.pop_front();
        }
        if (left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        }
        assert(left.size() == right.size() || left.size()+1 == right.size());
    }
public:
    FrontMiddleBackQueue() {  }

    void pushFront(int val) {
        left.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        right.push_front(val);;
        balance();
    }

    void pushBack(int val) {
        right.push_back(val);
        balance();
    }

    int popFront() {
        if (left.empty() && right.empty()) return -1;
        int res = -1;
        if (left.empty()) {
            res = right.front();
            right.pop_front();
            balance();
        } else {
            res = left.front();
            left.pop_front();
            balance();
        }
        return res;
    }

    int popMiddle() {
        if (left.empty() && right.empty()) return -1;
        int res = -1;
        if (left.size() == right.size()) {
            res = left.back();
            left.pop_back();
            balance();
        } else {
            res = right.front();
            right.pop_front();
            balance();
        }
        return res;
    }

    int popBack() {
        if (right.empty()) return -1;
        int res = right.back();
        right.pop_back();
        balance();
        return res;
    }
};


int main() {

}