#include <iostream>
#include <queue>
using namespace std;

// Solution 1 : two queues
class Stack_two {
private:
    queue<int> qs[2];
    int index;
    int l, r;
    void swapQ() {
        l = index;    
        r = l ^ 1;
        int ln = qs[l].size();
        while (--ln) {
            qs[r].push(qs[l].front());
            qs[l].pop();
        }
        index = r;
    }
public:
    Stack_two() {
        index = 0;
    }

    void push(int x) {
        qs[index].push(x);
    }

    void pop() {
        swapQ();
        qs[l].pop();
    }

    int top() {
        swapQ();
        int result = qs[l].front();
        qs[r].push(result); qs[l].pop();
        return result;
    }

    bool empty() {
        return qs[0].empty() && qs[1].empty(); 
    }
};


// Solution 2 : one queue, push then rotate to reverse order
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
