#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dp, top-down
class Solution {
public:
    vector<int> dp;

    int numberOfArrays(string s, int k) {
        int n = s.size();
        dp.resize(n, -1);
        return dfs(s, 0, k);
    }

    int dfs(const string& s, int i, int k) {
        if (i == s.size()) return 1;
        if (dp[i] != -1) return dp[i];
        int res = 0;
        long long num = 0;
        constexpr int kMod = 1e9+7;
        for (int j = i; j < s.size(); ++j) {
            num = num*10 + s[j]-'0';
            if (num > k) break;
            if (j+1 < s.size() && s[j+1] == '0') continue;
            res = (res + dfs(s, j+1, k)) % kMod;
        }
        return dp[i] = res;
    }
};

// dp, bottom-up, from end to begin
class Solution1 {
public:
    int numberOfArrays(string s, int k) {
        constexpr int kMod = 1e9+7;
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for (int i = n-1; i >= 0; --i) {
            if (s[i] == '0') continue;
            long long num = 0;
            for (int j = i; j < n; ++j) {
                num = num*10 + s[j]-'0';
                if (num > k) break;
                dp[i] = (dp[i] + dp[j+1]) % kMod;
            }
        }
        return dp[0];
    }
};


// dp, bottom-up, from begin to end
class Solution2 {
public:
    int numberOfArrays(string s, int k) {
        constexpr int kMod = 1e9+7;
        using ll = long long;
        int n = s.size();
        vector<ll> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            ll num = 0;
            for (int j = i; j >= 0; --j) {
                num = ll(s[j]-'0')*pow(10, i-j) + num;
                if (i-j > 10 || num > k) break;
                if (s[j] == '0') continue;
                dp[i] = (dp[i] + (j == 0 ? 1 : dp[j-1])) % kMod;
            }
        }
        return dp[n-1];
    }
};

int main() {
}
