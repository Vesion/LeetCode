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
        for (string& str : strs) {
            int ones = 0, zeroes = 0;
            for (char& c : str) {
                if (c == '1') ++ones;
                else ++zeroes;
            }
            for (int i = m; i >= zeroes; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-zeroes][j-ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};


int main() {
    return 0;
}
