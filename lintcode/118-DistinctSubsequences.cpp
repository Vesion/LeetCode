#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string &S, string &T) {
        int m = S.size(), n = T.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i <= m; ++i) dp[i][0] = 1;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i-1][j];
                if (S[i-1] == T[j-1]) dp[i][j] += dp[i-1][j-1];
            }
        }

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j)
                cout <<dp[i][j] << " ";
            cout << endl;
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    string s1 = "rabbbit";
    string s2 = "rabbit";
    cout << s.numDistinct(s1, s2) << endl;
    return 0;
}
