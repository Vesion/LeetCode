#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Solution 0 : dfs, TLE
// similiar to 131 solution 1, traverse every path to get the minimum cuts
// we do not implement here


// Solution 1 : dp
// 第一步：还是跟131 solution 2中一样，用dp的方法计算出s中任意子串s[i...j]是否是回文
// 第二步：任然用dp的方法，cuts[i]表示s[i...n-1]子串的最少cut数，在s[i...n-1]中，对于每一个回文子串s[i...j]（即dp[i][j]==ture的），
//      if j == n-1, cuts[i] = 0, 即整个s[i...n-1]是一个回文
//      else, cuts[i] = min(cuts[i], 1+cuts[j+1]), 即把s[i...n-1]分成s[i..j]和s[j+1...n-1]两部分，i<=j<=n-1, 在j迭代过程中求出最小的cuts[i]
// 最后，以上两步可以同时进行

int minCut(string s) {
    int n = s.size();
    if (n < 2) return 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    vector<int> cuts(n, 0);

    for (int i = 0; i < n; ++i) dp[i][i] = true; // single character is palindrome
    for (int i = n-1; i >= 0; --i) {
        cuts[i] = n-i-1; // init: cut every characters
        for (int j = i; j < n; ++j) {
            if (s[i] == s[j] && ((i+1 > j-1) || dp[i+1][j-1])) {
                dp[i][j] = true;
                if (j == n-1) cuts[i] = 0;
                else cuts[i] = min(cuts[i], cuts[j+1]+1);
            }
        }
    }
    
    return cuts[0];
}

int main() {
    cout << minCut("aab") << endl;
    return 0;
}
