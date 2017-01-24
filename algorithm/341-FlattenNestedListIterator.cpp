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
    stack<pair<vector<NestedInteger>::const_iterator, vector<NestedInteger>::const_iterator>> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        st.push({nestedList.begin(), nestedList.end()});
    }

    int next() {
        if (hasNext()) {
            int res = st.top().first->getInteger();
            st.top().first++;
            return res;
        }
        return -1;
    }

    bool hasNext() {
        while (!st.empty()) {
            if (st.top().first == st.top().second) st.pop(); // skip all empty vectors
            else {
                if (st.top().first->isInteger()) return true; // until we find a integer
                else {
                    auto& nlist = st.top().first->getList(); // here we must use auto&, because getList() return a reference
                    st.top().first++;
                    st.push({nlist.begin(), nlist.end()});
                }
            }
        }
        return false;
    }
};


int main() {
    return 0;
}

