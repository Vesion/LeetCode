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
class Solution_1 {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        if (nestedList.empty()) return 0;
        int height = getHeight(nestedList);
        return dfs(nestedList, height);
    }

    int getHeight(vector<NestedInteger> nestedList) {
        int height = 1;
        for (NestedInteger& ni : nestedList) {
            if (!ni.isInteger())
                height = max(height, getHeight(ni.getList())+1);
        }
        return height;
    }

    int dfs(vector<NestedInteger> nestedList, int height) {
        int res = 0;
        for (NestedInteger& ni : nestedList) {
            if (ni.isInteger()) res += ni.getInteger()*height;
            else res += dfs(ni.getList(), height-1);
        }
        return res;
    }
};


// Solution 2 : bfs, accumulate level by level
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int pre = 0;
        int res = 0;
        while (!nestedList.empty()) {
            vector<NestedInteger> nextLevel;
            for (NestedInteger& ni : nestedList) {
                if (ni.isInteger()) pre += ni.getInteger();
                else nextLevel.insert(nextLevel.end(), ni.getList().begin(), ni.getList().end());
            }
            res += pre;
            nestedList = nextLevel;
        }
        return res;
    }
};


int main() {
    return 0;
}
