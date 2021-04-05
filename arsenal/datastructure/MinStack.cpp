#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// MinStack is a stack (adapter) which supports push, top, pop, as well as min (return the minimal element in stack)
// All above operation can be done in O(1) time

class MinStack {
private:
    stack<int> es;
    stack<int> ms;
public:
    MinStack() {}

    void push(int x) {
        es.push(x);
        if (ms.empty() || x <= ms.top())
            ms.push(x);
    }

    void pop() {
        if (es.top() == ms.top()) ms.pop();
        es.pop();
    }

    int top() { return es.top(); }

    int min() { return ms.top(); }

    bool empty() { return es.empty(); }
};

int main() {
    vector<int> nums = {6, 5, 3, 2, 4, 1};    
    MinStack s;
    for (auto n : nums) {
        s.push(n);
        cout << s.min() << ' ';
    }
    cout <<endl;
    while (!s.empty()) {
        cout << s.min() << ' ';
        s.pop();
    }
    cout <<endl;
    return 0;
}
