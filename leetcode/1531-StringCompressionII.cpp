#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


// top-down dp
// dp[i][j] = the minimum encoding string for s starting from i with at most k deletes
class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int getLengthOfOptimalCompression(string s, int k) {
        n = s.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return dfs(s, 0, k);
    }

    int dfs(const string& s, int i, int k) {
        if (i >= n || n-i <= k) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        int res = n;
        int m[26] = {}, maxc = 0;
        for (int j = i; j < n; ++j) {
            maxc = max(maxc, ++m[s[j]-'a']);
            // number of deletes = length of substring - most frequent occurrences
            int deletes = (j-i+1 - maxc);
            if (deletes <= k) res = min(res, count(maxc)+1 + dfs(s, j+1, k-deletes));
            else break;
        }
        return dp[i][k] = res;
    }

    int count(int num) {
        if (num == 1) return 0;
        int res = 0;
        for (; num; num /= 10) ++res;
        return res;
    }
};

int main() {

}