#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return {};
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<int> cuts(n, 0); // cuts[i] means the min cuts of s[i...n-1] 

        for (int i = 0; i < n; ++i) dp[i][i] = true;
        for (int i = n-1; i >= 0; --i) {
            cuts[i] = n-i-1; // init, cut every character
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (i+1 > j-1 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if (j == n-1) cuts[i] = 0; // s[i...n-1] is a palindrome, so no cuts
                    else cuts[i] = min(cuts[i], cuts[j+1]+1);  // s[i...j] is a palindrome, so cuts[i] = cuts[j+1] plus this one
                }
            }
        }

        return cuts[0];
    }
};


int main() {
    Solution s;
    cout << s.minCut("ababababababababababababcbabababababababababababa") <<endl;
    return 0;
}

