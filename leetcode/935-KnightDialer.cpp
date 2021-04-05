#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// straight forward DP, O(N)
class Solution {
public:
    int knightDialer(int n) {
        // go[i][j] is the number could reach starting from i
        const vector<int> go[10] = {
            {4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9},
            {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}
        };
        int res = 0;
        constexpr int kMod = 1e9 + 7;
        vector<int> dp(10, 1);
        for (int i = 0; i < n-1; ++i) {
            vector<int> ndp(10, 0);
            for (int j = 0; j <= 9; ++j) {
                for (int nj : go[j]) {
                    ndp[nj] = (ndp[nj] + dp[j]) % kMod;
                }
            }
            swap(dp, ndp);
        }
        for (int i : dp) res = (res + i) % kMod;
        return res;
    }
};


// could use matrix multiplication to optimize to O(logN)
// https://leetcode.com/problems/knight-dialer/discuss/189252/O(logN)

int main() {
}
