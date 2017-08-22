#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

class Queue {
private:
    stack<int> newst, oldst;

public:
    void push(int x) {
        newst.push(x);
    }

    void pop(void) {
        peek();
        oldst.pop();
    }

    int peek(void) {
        if (oldst.empty()) {
            while (!newst.empty()) {
                oldst.push(newst.top()); newst.pop();
            } 
        }
        return oldst.top();
    }

    bool empty(void) {
        return newst.empty() && oldst.empty();
    }
};

int main() {
    return 0;
}
