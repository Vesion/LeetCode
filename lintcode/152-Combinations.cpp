#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    
    void dfs(int n, int k, int cur) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = cur; i <= n; ++i) {
            path.push_back(i);
            dfs(n, k, i+1);
            path.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k) {
        dfs(n, k, 1);
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}
