#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Brute-force, O(m*m), TLE
class Solution0 {
public:
    string minWindow(string S, string T) {
        if (S.size() < T.size()) return "";
        int min_length = S.size();
        int min_start = -1;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] != T[0]) continue;
            const int length = subs(S, i, T);
            if (length < min_length) {
                min_length = length;
                min_start = i;
            }
        }
        if (min_start == -1) return "";
        return S.substr(min_start, min_length);
    }

    int subs(const string& S, int start, const string& T) {
        int i = start, j = 0;
        while (i < S.size() && j < T.size()) {
            if (S[i++] == T[j]) ++j;
        }
        if (j == T.size()) return i - start;
        return S.size();
    }
};

// DP, O(m*n)
// dp[i][j] = min l, subject to T[0:j] is subsequence of S[i-l, i]
class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        for (int i = 0; i <= m; ++i) dp[i][0] = 0;

        for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) {
            if (S[i-1] == T[j-1]) {
                if (dp[i-1][j-1] != INT_MAX) dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i-1][j] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            } else {
                if (dp[i-1][j] != INT_MAX) dp[i][j] = dp[i-1][j] + 1;
            }
        }

        int r = -1, l = INT_MAX;
        for (int i = 1; i <= m; ++i) {
            if (dp[i][n] < l) {
                r = i;
                l = dp[i][n];
            }
        }
        return r == -1 ? "" : S.substr(r-l, l);
    }
};


int main() {
  return 0;
}
