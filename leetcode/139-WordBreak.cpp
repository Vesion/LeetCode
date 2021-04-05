#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n+1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (dp[j] && m.count(s.substr(j, i-j+1))) {
                    dp[i+1] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};


int main() {
    return 0;
}

