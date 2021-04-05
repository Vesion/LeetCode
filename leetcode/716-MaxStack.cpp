#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <map>
using namespace std;

// list + ordered map
class MaxStack {
public:
    /** initialize your data structure here. */
    list<int> st;
    using It = list<int>::iterator;
    map<int, vector<It>> m;

    MaxStack() {  }

    void push(int x) {
        st.push_back(x);
        m[x].push_back(prev(st.end()));
    }

    int pop() {
        int x = st.back();
        st.pop_back();
        m[x].pop_back();
        if (m[x].empty()) m.erase(x);
        return x;
    }

    int top() {
        return st.back();
    }

    int peekMax() {
        return m.rbegin()->first;
    }

    int popMax() {
        auto it = prev(m.end());
        st.erase(it->second.back());
        it->second.pop_back();
        int x = it->first;
        if (it->second.empty()) m.erase(it);
        return x;
    }
};


int main() {
}
