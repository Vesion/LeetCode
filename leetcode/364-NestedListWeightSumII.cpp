#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    NestedInteger();
    NestedInteger(int value);
    bool isInteger() const;
    int getInteger() const;
    void setInteger(int value);
    void add(const NestedInteger &ni);
    const vector<NestedInteger> &getList() const;
};

// Solution 1 : trivial dfs, two passes
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nl) {
        if (nl.empty()) return 0;
        int maxdepth = depth(nl);
        return dfs(nl, maxdepth);
    }

    int depth(const vector<NestedInteger>& nl) {
        int res = 1;
        for (const auto& ni : nl) {
            if (!ni.isInteger()) res = max(res, depth(ni.getList()) + 1);
        }
        return res;
    }

    int dfs(const vector<NestedInteger>& nl, int depth) {
        int res = 0;
        for (const auto& ni : nl) {
            if (ni.isInteger()) res += depth * ni.getInteger();
            else res += dfs(ni.getList(), depth-1);
        }
        return res;
    }
};


// Solution 2 : bfs, accumulate level by level
class Solution1 {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int pre = 0, res = 0;
        while (!nestedList.empty()) {
            vector<NestedInteger> nl;
            for (const NestedInteger& ni : nestedList) {
                if (ni.isInteger()) pre += ni.getInteger();
                else nl.insert(nl.end(), ni.getList().begin(), ni.getList().end());
            }
            res += pre;
            swap(nestedList, nl);
        }
        return res;
    }
};


int main() {
    return 0;
}
