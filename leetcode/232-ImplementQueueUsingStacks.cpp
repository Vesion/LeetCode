#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> newst, oldst;

public:
    MyQueue() {}

    void push(int x) {
        newst.push(x);
    }

    int pop() {
        int x = peek();
        oldst.pop();
        return x;
    }

    int peek() {
        if (oldst.empty()) {
            while (!newst.empty()) {
                oldst.push(newst.top()); newst.pop();
            }
        }
        return oldst.top();
    }

    bool empty() {
        return newst.empty() && oldst.empty();
    }
};

int main() {
    return 0;
}
