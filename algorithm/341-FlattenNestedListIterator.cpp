#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    using nit = vector<NestedInteger>::const_iterator;
    stack<pair<nit, nit>> st;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if (!nestedList.empty()) {
            st.push({nestedList.begin(), nestedList.end()});
        }
    }

    int next() {
        if (hasNext()) return (st.top().first++)->getInteger(); // we have skiped all empty vector in hasNext(), so here can get integer directly
        return 0; // never
    }

    bool hasNext() {
        while (!st.empty()) {
            if (st.top().first == st.top().second) // if current vector has been iterated done, pop it; this can skip empty vectors
                st.pop();
            else {
                auto it = st.top().first;
                if (it->isInteger()) return true; // if it is an integer, return true directly
                st.top().first++;
                auto& v = it->getList();
                st.push({v.begin(), v.end()}); // else push the vector's begin and end
            }
        }
        return false;
    }
};


int main() {
    return 0;
}

