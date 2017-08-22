#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), m = days[0].size();    
        vector<vector<int>> dp(m+1, vector<int>(n, -1));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if ((j == k || flights[k][j]) && (dp[i-1][k] != -1)) dp[i][j] = max(dp[i][j], dp[i-1][k]+days[j][i-1]);
                }
            }
        }
        int res = 0;
        for (int j = 0; j < n; ++j) res = max(res, dp[m][j]);
        return res;
    }
};


int main() {
    return 0;
}
