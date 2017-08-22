#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
    }

    void push(int element) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(element);
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
    
    int pop() {
        int t = stack1.top();
        stack1.pop();
        return t;
    }

    int top() {
        return stack1.top();
    }
};


int main() {
    
    return 0;
}
