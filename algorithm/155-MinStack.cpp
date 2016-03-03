#include <iostream>
#include <stack>
using namespace std;

// Solution 1: uses two stack, one in push order, one in sorted order for retrieve min value
class MinStack {
private:
    stack<int> _ps;
    stack<int> _ss;

public:
    void push(int x) {
        _ps.push(x); 
        if (_ss.empty() || x <= getMin()) _ss.push(x);

    }

    void pop() {
        if (_ps.top() == getMin()) _ss.pop();
        _ps.pop(); 
    }

    int top() {
        return _ps.top(); 
    }

    int getMin() {
        return _ss.top();
    }
};


// Soltuon 2 : uses only one stack, store the gap between the min value and the current value
// we do not implement here

int main() {
    MinStack s;
    s.push(4);
    cout << s.getMin() << endl;
    s.push(1);
    cout << s.getMin() << endl;
    s.push(6);
    cout << s.getMin() << endl;
    cout << s.top() << endl;
    s.pop();
    s.pop();
    cout << s.top() << endl;
    cout << s.getMin() << endl;
    return 0;
}
