#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

class MinStack {
public:
    stack<int> es;
    stack<int> ms;

    MinStack() {
    }

    void push(int number) {
        es.push(number);
        if (ms.empty() || number <= ms.top()) ms.push(number);
    }

    int pop() {
        int t = es.top();
        es.pop();
        if (ms.top() == t) ms.pop();
        return t;
    }

    int min() {
        return ms.top();
    }
};

int main() {
    return 0;
}
