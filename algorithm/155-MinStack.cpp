#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// Solution 1 : two stacks
class MinStack {
private:
    stack<int> st, min_st;

public:
    MinStack() { }
    
    void push(int x) {
        st.push(x);
        if (min_st.empty() || x <= min_st.top()) min_st.push(x);
    }
    
    void pop() {
        if (st.top() == min_st.top()) min_st.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};


// Solution 2 : one stack
class MinStack_2 {
public:
    stack<int> st;
    int minx;

    MinStack_2() {
        minx = INT_MAX; 
    }
    
    void push(int x) {
        if (x <= minx) {
            st.push(minx);
            minx = x;
        }
        st.push(x);
    }
    
    void pop() {
        int x = st.top(); st.pop(); 
        if (x == minx) {
            minx = st.top();
            st.pop();
        }
    }
    
    int top() {
        return st.top(); 
    }
    
    int getMin() {
        return minx; 
    }
};


int main() {
    return 0;
}

