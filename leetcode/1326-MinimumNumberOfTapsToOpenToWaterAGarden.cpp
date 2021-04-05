#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// dp, O(n*m), m is the max range of r[i]
class Solution1 {
public:
    int minTaps(int n, vector<int>& r) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = max(0, i-r[i]+1); j <= min(n, i+r[i]); ++j) {
                if (dp[max(0, i-r[i])] != INT_MAX) {
                    dp[j] = min(dp[j], dp[max(0, i-r[i])]+1);
                }
            }
        }
        return dp[n] != INT_MAX ? dp[n] : -1;
    }
};

// sort intervals, O(nlogn)
class Solution2 {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> vs;
        for (int i = 0; i < n+1; ++i) {
            if (ranges[i] == 0) continue;
            vs.push_back({i-ranges[i], i+ranges[i]});
        }
        if (vs.empty()) return -1;
        sort(vs.begin(), vs.end());

        int start = 0, end = 0, res = 0, m = vs.size();
        for (int i = 0; i < m; ) {
            while (i < m && vs[i][0] <= start) end = max(end, vs[i++][1]);
            if (end <= start) return -1;
            start = end;
            ++res;
            if (start >= n) break;
        }
        return res;
    }
};

// greedy, O(n), similar to 045-JumpGameII
class Solution {
public:
    int minTaps(int n, vector<int>& r) {
        // firstly generate the jump array, jump[i] = the max jump distance at position i
        vector<int> jump(n+1, 0);
        for (int i = 0; i <= n; ++i) {
            int left = max(0, i-r[i]), right = min(n, i+r[i]);
            jump[left] = max(jump[left], right-left);
        }

        // then it's equal to 045-JumpGameII, but need to check unreachable position
        int max_end = 0, end = 0;
        int res = 0;
        for (int i = 0; i <= n; ++i) {
            if (i > end) {
                if (max_end == end) return -1;
                end = max_end;
                ++res;
            }
            max_end = max(max_end, i+jump[i]);
        }
        return res;
    }
};

int main() {
}
