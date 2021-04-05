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
    using S = vector<NestedInteger>::const_iterator;
    stack<pair<S,S>> st;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        st.push({nestedList.begin(), nestedList.end()});
    }

    int next() {
        if (hasNext()) {
            int res = st.top().first->getInteger();
            ++st.top().first;
            return res;
        }
        return -1;
    }

    bool hasNext() {
        while (!st.empty()) {
            if (st.top().first == st.top().second) st.pop();
            else {
                if (st.top().first->isInteger()) return true;
                const auto& l = st.top().first->getList();
                ++st.top().first;
                st.push({l.begin(), l.end()});
            }
        }
        return false;
    }
};


int main() {
    return 0;
}

