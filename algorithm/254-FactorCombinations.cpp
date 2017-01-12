#include <iostream>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// backtracking, no trivial, think about how to construct path in some order
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(n, path, res);
        return res;
    }
    
    void dfs(int n, vector<int>& path, vector<vector<int>>& res) {
        int i = path.empty() ? 2 : path.back();
        // prune, i <= n/i
        // ensure each candidate factor won't be larger than n/factor
        // meanwhile, it ensures the order of factors in path
        for (; i <= n/i; ++i) {
            if (n % i == 0) {
                path.push_back(i);

                path.push_back(n/i);
                res.push_back(path);
                path.pop_back();

                dfs(n/i, path, res);
                path.pop_back();
            }
        }
    }
};


int main() {
    Solution s;
    auto r = s.getFactors(32);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}
