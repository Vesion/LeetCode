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



// Solution 1 : naive dp, O(n^2)
class Solution_1 {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        vector<int> dp(n, 1);
        int res = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};


// Solution 2 : dp + binary search, similar to LIS
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        // Note: sort with width first, when widths equal, the one with greater height goes first
        sort(envelopes.begin(), envelopes.end(), [](const pair<int,int>& e1, const pair<int,int>& e2) {
            if (e1.first == e2.first) return e1.second > e2.second;
            return e1.first < e2.first;
        });
        
        vector<int> lis;
        for (auto& e : envelopes) {
            auto it = lower_bound(lis.begin(), lis.end(), e.second);
            if (it == lis.end()) lis.push_back(e.second);
            else *it = e.second;
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
