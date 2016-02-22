#include <iostream>
#include <vector>
using namespace std;

// classical dp problem
// dp[i][j]表示s[...i]和t[...j]匹配的结果，则dp[i][j]至少是dp[i-1][j]，如果s[i]==t[j]，那么dp[i][j]还要加上s[...i-1]和t[...j-1]匹配的结果，即dp[i-1][j-1]
// 当然也可以用dfs做，但必然超时

// Solution 1 : dp with 2D array
int numDistinct_2d(string s, string t) {
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 0; i <= m; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = dp[i-1][j] + (s[i-1] == t[j-1] ? dp[i-1][j-1] : 0);
    
    // dp output
    for (auto i : dp) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return dp[m][n];
}

// Solution 2 : dp with scrolling array(save space, faster)
int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 0; i < m; ++i)
        for (int j = n-1; j >= 0; --j)
            dp[j+1] += (s[i] == t[j] ? dp[j] : 0);
    return dp[n];
}

int main() {
    cout << numDistinct_2d("rabbbit", "rabbit") << endl;
    cout << numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}
