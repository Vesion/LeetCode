#include <iostream>
#include <cmath> 
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : trivial backtracking + prune
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(n, 2, path, res);
        return res;
    }
    
    void dfs(int n, int start, vector<int>& path, vector<vector<int>>& res) {
        if (n == 1) {
            if (path.size() > 1) res.push_back(path);
            return;
        }
        for (int i = start; i <= n; ++i) {
            // a very efficient prune, think about it
            // all factors must be in range [1, sqrt(n)], other than n itself
            if (i > sqrt(n)) i = n; 

            if (n % i == 0) {
                path.push_back(i);
                dfs(n/i, i, path, res);
                path.pop_back();
            }
        }
    }
};


// Solution 2 : none trivial, think about how to construct path in some order
class Solution_2 {
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
