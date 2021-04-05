#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// NP-hard, bitmask DP, O(2^n)
// https://leetcode.com/problems/parallel-courses-ii/discuss/708263/Can-anyone-explain-the-bit-mask-method
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> pre(n); // pre[i]: the bit representation of all dependencies of course i
        for(auto& e : dependencies){
            e[0] -= 1;
            e[1] -= 1;
            pre[e[1]] |= 1 << e[0];
        }
        // i is the bit representation of a combination of courses.
        // dp[i] is the minimum days to complete all the courses
        vector<int> dp(1 << n, n);
        dp[0] = 0;
        for(int i = 0; i < (1 << n); i += 1){
            int ex = 0;
            // find  out ex, the bit representation of the all courses that we can study now
            // since we have i and pre[j], we know course j can be studied if i contains all it's prerequisites ((i & pre[j]) == pre[j])
            for(int j = 0; j < n; j += 1) if((i & pre[j]) == pre[j]) ex |= 1 << j;
            ex &= ~i;
            // enumerate all the bit 1 combinations of ex
            // this is a typical method to enumerate all subsets of a bit representation:
            // for (int i = s; i; i = (i - 1) &ｓ)
            // https://cp-algorithms.com/algebra/all-submasks.html
            for(int s = ex; s; s = (s - 1) & ex) if(__builtin_popcount(s) <= k){
                dp[i | s] = min(dp[i | s], dp[i] + 1);
            }
        }
        return dp.back();
    }
};

int main() {

}
