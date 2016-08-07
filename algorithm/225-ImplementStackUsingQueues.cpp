#include <iostream>
#include <queue>
using namespace std;

// one queue, push then rotate to reverse order
class Stack {
public:
    queue<int> que;
    void push(int x) {
        que.push(x);
        for(int i = 0; i < que.size()-1; ++i){
            que.push(que.front());
            que.pop();
        }
    }

    void pop() {
        que.pop();
    }

    int top() {
        return que.front();
    }

    bool empty() {
        return que.empty();
    }
};

int main() {
    Stack s;
    cout << s.empty() << endl;
    s.push(1); s.push(2); s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.empty() << endl;
    return 0;
}
