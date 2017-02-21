#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }
    
    int dfs(const vector<NestedInteger>& nestedList, int depth) {
        int res = 0;
        for (auto& e : nestedList) {
            if (e.isInteger()) res += e.getInteger() * depth;
            else res += dfs(e.getList(), depth+1);
        }
        return res;
    }
};


int main() {
    return 0;
}
