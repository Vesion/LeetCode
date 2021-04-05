#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 0 : dfs+memo to find the longest path in a DAG, O(n^2), TLE
class Solution_0 {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0;
        int n = envelopes.size();
        vector<vector<bool>> inc(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) // envelope cannot be rotated
                    inc[i][j] = true;
            }
        }

        vector<int> path(n, 0);
        int res = 0;
        for (int i = 0; i < n; ++i)
            res = max(res, dfs(i, n, path, inc));
        return res;
    }

    int dfs(int cur, int n, vector<int>& path, vector<vector<bool>>& inc) {
        if (path[cur]) return path[cur];
        int res = 1;
        for (int i = 0; i < n; ++i) {
            if (inc[cur][i]) res = max(res, dfs(i, n, path, inc)+1);
        }
        path[cur] = res;
        return res;
    }
};



// Solution 1 : naive dp in LIS problem
class Solution_1 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        vector<int> dp(n, 1);
        int res = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};


// Solution 2 : dp + binary search in LIS problem
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Note: sort with width first, when widths equal, the one with greater height goes first
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& e1, const vector<int>& e2) {
                 if (e1[0] == e2[0]) return e1[1] > e2[1];
                 return e1[0] < e2[0];
             });
        vector<int> lis;
        for (const auto& e : envelopes) {
            auto it = lower_bound(lis.begin(), lis.end(), e[1]);
            if (it == lis.end()) lis.push_back(e[1]);
            else *it = e[1];
        }
        return lis.size();
    }
};


int main() {
    Solution s;
    vector<pair<int,int>> e = { { 5,4 },{ 6,4 },{ 6,7 },{ 2,3 } };
    cout << s.maxEnvelopes(e) <<endl;
    return 0;
}
