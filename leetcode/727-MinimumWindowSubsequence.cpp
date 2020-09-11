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
class Solution {
public:
    string minWindow(string S, string T) {
        const int m = S.size();
        const int n = T.size();
        constexpr int kMax = numeric_limits<int>::max();
        vector<vector<int>> dp(m+1, vector<int>(n+1, kMax));
        for (int i = 0; i < m+1; ++i) dp[i][0] = 0;

        for (int i = 1; i < m+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                if (S[i-1] == T[j-1]) {
                    if (dp[i-1][j-1] != kMax) dp[i][j] = dp[i-1][j-1] + 1;
                    if (dp[i-1][j] != kMax) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                } else {
                    if (dp[i-1][j] != kMax) dp[i][j] = dp[i-1][j] + 1;
                }
            }
        }

        int min_l = kMax, min_i = -1;
        for (int i = 1; i < m+1; ++i) {
            if (dp[i][n] < min_l) {
                min_l = dp[i][n];
                min_i = i;
            }
        }
        if (min_i == -1) return "";
        return S.substr(min_i-min_l, min_l);
    }
};


int main() {
  return 0;
}
