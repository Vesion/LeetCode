#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<pair<vector<int>, int>> tree;

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        tree.resize(n);
        for (int i = 0; i < n; ++i) tree[i].second = 0;
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) tree[manager[i]].first.push_back(i);
            tree[i].second = informTime[i];
        }
        return dfs(headID);
    }

    // Maximum depth of the tree
    int dfs(int root) {
        int res = 0;
        const int d = tree[root].second;
        for (const int child : tree[root].first) {
            res = max(res, dfs(child) + d);
        }
        return res;
    }
};

int main() {
}
