#include <iostream>
#include <vector>
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


// Solution 1 : Simply flatten the nestedList, means we need to copy the entire data
class NestedIterator_flatten {
private:
    using Nivit = vector<NestedInteger>::const_iterator;
    using Ivit = vector<int>::const_iterator;

    vector<int> flattenList;
    Ivit flit;

    void flatten(Nivit start, Nivit end) {
        if (start == end) return;
        for (Nivit it = start; it != end; ++it) {
            if (it->isInteger()) flattenList.push_back(it->getInteger());
            else {
                auto& v = it->getList();
                flatten(v.begin(), v.end());
            }
        }
    }
public:
    NestedIterator_flatten(vector<NestedInteger> &nestedList) {
        flatten(nestedList.begin(), nestedList.end());
        flit = flattenList.begin();
    }

    int next() {
        return *flit++;
    }

    bool hasNext() {
        return flit != flattenList.end();
    }
};


// Solution 2 : the real iterator, use stack to simulate recursion
class NestedIterator {
private:
    // two stacks, one for current NestedInteger vector's current iterator, one for its end iterator
    stack<vector<NestedInteger>::const_iterator> its;
    stack<vector<NestedInteger>::const_iterator> ends;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        its.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        hasNext();
        return (its.top()++)->getInteger();
    }

    bool hasNext() {
        while (!its.empty()) {
            if (its.top() == ends.top()) { // current vector over
                its.pop();
                ends.pop();
            } else {
                auto it = its.top();
                if (it->isInteger()) return true;
                its.top()++; // before push next vector's begin and end, advance current one
                its.push(it->getList().begin());
                ends.push(it->getList().end());
            }
        }
        return false;
    }
};


// Cannot run because we do not implement NestedInteger class
int main() {
    vector<NestedInteger> nestedList;
    NestedIterator i(nestedList);
    while (i.hasNext()) cout << i.next() << endl;
    return 0;
}
