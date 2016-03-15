#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s;
public:
    void push(int x) {
        stack<int> t;
        while (!s.empty()) t.push(s.top()), s.pop();
        s.push(x);
        while (!t.empty()) s.push(t.top()), t.pop();
    }

    void pop(void) {
        s.pop();
    }

    int peek(void) {
        return s.top();
    }

    bool empty(void) {
        return s.empty();
    }
};

int main() {
    Queue q;
    cout << q.empty() << endl;
    q.push(1); q.push(2); q.push(3);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.empty() << endl;
    return 0;
}
