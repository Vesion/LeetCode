#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dp, O(n)
// can be optimized by fast matrix power, to O(logn)
class Solution {
public:
    int checkRecord(int n) {
        int dp[2][2][3] = {{{0}}};
        dp[0][0][0] = 1;
        int p = 0;
        for (int i = 0; i < n; ++i) {
            memset(dp[1-p], 0, sizeof dp[1-p]);
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    add(dp[1-p][j][0], dp[p][j][k]); // put 'P'
                    if (j == 0) add(dp[1-p][1][0], dp[p][j][k]); // put 'A'
                    if (k < 2) add(dp[1-p][j][k+1], dp[p][j][k]); // put 'L'
                }
            }
            p = 1-p;
        }
        int res = 0;
        for (int j = 0; j < 2; ++j) for (int k = 0; k < 3; ++k) add(res, dp[p][j][k]);
        return res;
    }

    const static int MOD = 1e9+7;
    void add(int& a, int b) {
        a += b;
        if (a >= MOD) a -= MOD;
    }
};


int main() {
    Solution s;
    cout << s.checkRecord(2) << endl;
    return 0;
}
