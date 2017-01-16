#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
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

