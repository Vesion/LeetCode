#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = (s[1] != '0') + (isAplha(s[0], s[1]));
        for (int i = 2; i < n; ++i) {
            if (s[i] != '0') dp[i] = dp[i-1]; // s[i] can be decoded
            if (isAplha(s[i-1], s[i])) dp[i] += dp[i-2]; // s[i-1,i] can be decoded
        }
        return dp[n-1];
    }

    bool isAplha(char c1, char c2) {
        if (c1 == '0') return false;
        int a = (c1-'0')*10 + (c2-'0');
        return a >= 1 && a <= 26;
    }
};

int main() {
    Solution s;
    cout << s.numDecodings("110");
    return 0;
}

