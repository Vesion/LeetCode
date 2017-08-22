#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> tree;
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        for (int i = 0; i < n; ++i)
            tree[ppid[i]].push_back(pid[i]);
        dfs(kill);
        return res;
    }
    
    vector<int> res;
    void dfs(int root) {
        res.push_back(root);
        for (int& child : tree[root]) dfs(child);
    }
};

int main() {
    Solution s;
    return 0;
}
