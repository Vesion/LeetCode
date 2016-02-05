#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 一开始想到是用先求公共子序列，再用子序列求解，但是结果大部分是错的，故参考别人
// 发现换了状态表示和递归方程的意义，不过跟LCS差不多
// 编辑距离其实是DP里的经典问题，可参考wiki

int minDistance(string word1, string word2) {
    int n1 = word1.size(), n2 = word2.size();
    if (n1 > n2) return minDistance(word2, word1);
    if (n1 == 0) return n2;
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for (int i = 0; i <= n1; ++i) dp[i][0] = i;
    for (int j = 0; j <= n2; ++j) dp[0][j] = j;
    
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else {
                int insertW = dp[i-1][j] + 1;
                int deleteW = dp[i][j-1] + 1;
                int replaceW = dp[i-1][j-1] + 1;
                dp[i][j] = min(insertW, min(deleteW, replaceW));
            }
        }
    }
    return dp[n1][n2];
}

int main() {
    cout << minDistance("ab23t", "a1b2c3") << endl;
    cout << minDistance("a", "a1b2c3") << endl;
    cout << minDistance("mart", "karma") << endl;
    cout << minDistance("", "") << endl;
    cout << minDistance("ab", "bc") << endl;
    return 0;
}
