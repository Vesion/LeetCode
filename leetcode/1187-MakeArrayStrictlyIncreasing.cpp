#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Top down dp
class Solution {
public:
    vector<vector<int>> dp;
    int m, n;
    static constexpr int kMax = 2e3+5;

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        m = arr1.size(), n = arr2.size();
        dp.resize(m+1, vector<int>(n+1, -1));
        int res = dfs(arr1, arr2, 0, 0, INT_MIN);
        return res >= kMax ? -1 : res;
    }

    int dfs(const vector<int>& a1, const vector<int>& a2, int i1, int i2, int prev) {
        if (i1 >= m)  return 0;
        i2 = upper_bound(a2.begin() + i2, a2.end(), prev) - a2.begin();
        if (dp[i1][i2] != -1) return dp[i1][i2];
        int res = kMax;
        if (i2 < n) res = min(res, 1 + dfs(a1, a2, i1 + 1, i2, a2[i2]));
        if (prev < a1[i1])  res = min(res, dfs(a1, a2, i1 + 1, i2, a1[i1]));
        return dp[i1][i2] = res;
    }
};


// https://leetcode.com/problems/make-array-strictly-increasing/discuss/377403/Python-DP-solution-with-explanation.
class Solution1 {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        // dp[num][c] = when reach arr1[i], minimum operations to make arr1[i] be num
        // (whether choose number from arr2 or not)
        unordered_map<int, int> dp;
        dp[-1] = 0;
        for (int cur : arr1) {
            unordered_map<int, int> ndp;
            for (const auto& p : dp) {
                int prev = p.first, c = p.second;
                // if arr[i] > arr[i-1], we can choose not to replace arr[i]
                if (cur > prev) {
                    auto it = ndp.find(cur);
                    if (it == ndp.end()) ndp[cur] = c;
                    else it->second = min(it->second, c);
                }
                // at any time, we can choose to replace arr[i] with a number from
                // arr2 that is greater than arr[i-1]
                auto uit = upper_bound(arr2.begin(), arr2.end(), prev);
                if (uit != arr2.end()) {
                    int new_cur = *uit;
                    auto it = ndp.find(new_cur);
                    if (it == ndp.end()) ndp[new_cur] = c+1;
                    else it->second = min(it->second, c+1);
                }
            }
            swap(dp, ndp);
        }
        if (dp.empty()) return -1;
        int res = INT_MAX;
        for (const auto& p : dp) res = min(res, p.second);
        return res;
    }
};

int main() {

}
