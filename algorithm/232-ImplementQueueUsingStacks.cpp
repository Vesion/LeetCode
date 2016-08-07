#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> olds, news;
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

    void pop(void) {
        MoveNewToOld();
        olds.pop();
    }

    int peek(void) {
        MoveNewToOld();
        return olds.top();
    }

    bool empty(void) {
        return olds.empty() && news.empty();
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
