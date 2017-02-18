#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : backtracking
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(n, 1, k, path, res);
        return res;
    }
    
    void dfs(int n, int start, int k, vector<int>& path, vector<vector<int>>& res) {
        if ((int)path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= n; ++i) {
            path.push_back(i);
            dfs(n, i+1, k, path, res);
            path.pop_back();
        }
    }
};


// Solution 2 : C(n,k)=C(n-1,k-1)+C(n-1,k)
class Solution_2 {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k == n || k == 0) {
            vector<int> path;
            for (int i = 1; i <= k; ++i) path.push_back(i);
            return vector<vector<int>>({path});
        }
        auto left = combine(n-1, k-1); // number n is selected
        for (auto& path : left) path.push_back(n);
        auto right = combine(n-1, k); // number n is not selected
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};


int main() {
    Solution_2 s;
    auto r = s.combine(4, 2);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}

