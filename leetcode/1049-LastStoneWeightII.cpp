#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dfs, TLE
class Solution0 {
public:
    int n;
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();
        return dfs(stones, (1<<n)-1);
    }

    int dfs(vector<int>& s, int cur) {
        if (cur == 0) return 0;
        if (__builtin_popcount(cur) == 1) {
            int i = __builtin_ctz(cur);
            return s[i];
        }
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (((cur>>i)&1) == 0) continue;
            for (int j = i+1; j < n; ++j) {
                if (((cur>>j)&1) == 0) continue;
                if (s[i] == s[j]) {
                    res = min(res, dfs(s, cur ^ (1<<i) ^ (1<<j)));
                } else {
                    if (s[i] > s[j]) {
                        s[i] -= s[j];
                        res = min(res, dfs(s, cur ^ (1<<j)));
                        s[i] += s[j];
                    } else {
                        s[j] -= s[i];
                        res = min(res, dfs(s, cur ^ (1<<i)));
                        s[j] += s[i];
                    }
                }
            }
        }
        return res;
    }
};


// dp, convert the problem to:
// divide all numbers into two groups, find the minimum difference between the sum of two groups
// https://leetcode.com/problems/last-stone-weight-ii/discuss/294888/JavaC%2B%2BPython-Easy-Knapsacks-DP
// dp[i] = whether we can choose some nums from the array which sum is i
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        constexpr int kMax = 30*100+5;
        vector<bool> dp(kMax, false);
        dp[0] = true;
        int sum = 0;
        for (int s : stones) {
            sum += s;
            for (int i = sum; i >= s; --i) {
                dp[i] = dp[i] | dp[i-s];
            }
        }
        for (int i = sum/2; i >= 0; --i) {
            if (dp[i]) return sum-i-i;
        }
        return 0;
    }
};

int main() {
}
