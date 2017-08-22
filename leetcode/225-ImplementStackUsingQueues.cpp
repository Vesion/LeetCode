#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

class Stack {
private:
    queue<int> q;
public:
    void push(int x) {
        int len = q.size();
        q.push(x);
        while (len--) {
            int t = q.front();
            q.pop();
            q.push(t);
        }
    }

    void pop() {
        q.pop();
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};


int main() {
    return 0;
}

