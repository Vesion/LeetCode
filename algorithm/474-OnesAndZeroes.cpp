#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to 01-knapsack problem

// dp[i][j][k] = the max number of strings that can be formed with i 0's and j 1's
// O(l*(k+mn)), k is the average length of strings
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < (int)strs.size(); ++i) {

            int zeroes = 0, ones = 0;
            for (char c : strs[i]) {
                if (c == '0') ++zeroes;
                else ++ones;
            }

            for (int j = m; j >= zeroes; --j) {
                for (int k = n; k >= ones; --k) {
                    dp[j][k] = max(dp[j][k], dp[j-zeroes][k-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    vector<string> strs = {"10", "0", "1"};
    cout << s.findMaxForm(strs, 1, 1) << endl;
    return 0;
}
