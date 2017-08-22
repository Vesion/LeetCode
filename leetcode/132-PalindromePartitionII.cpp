#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<int> cuts(n, 0); // cuts[i] means the min cuts of s[0,i]

        for (int j = 1; j < n; ++j) {
            cuts[j] = j;
            for (int i = j; i >= 0; --i) {
                if (s[i] == s[j] && (i+1 > j-1 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if (i == 0) cuts[j] = 0;
                    else cuts[j] = min(cuts[j], cuts[i-1]+1);
                }
            }
        }
        return cuts[n-1];
    }
};


int main() {
    Solution s;
    cout << s.minCut("ababababababababababababcbabababababababababababa") <<endl;
    return 0;
}
