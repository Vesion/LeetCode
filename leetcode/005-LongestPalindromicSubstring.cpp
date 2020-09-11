#include <iostream>
#include <vector>
#include <string>
using namespace std;


// Solution 1: extend from each position, O(n^2)
// traverse the whole string, start finding the palindrome from each char (extend to left and right), get the longest substr
class Solution1 {
public:
    string longestPalindrome(string s) {
        int maxi = 0, maxl = 0;
        for (int i = 0; i < s.size(); ++i) {
            const auto p = max_palindrom(s, i);
            if (p.second > maxl) {
                maxl = p.second;
                maxi = p.first;
            }
        }
        return s.substr(maxi, maxl);
    }

    pair<int,int> max_palindrom(const string& s, int start) {
        int l1 = 1;
        for (int i = start-1, j = start+1; i >= 0 && j < s.size(); --i, ++j) {
            if (s[i] != s[j]) break;
            l1 += 2;
        }
        int l2 = 0;
        for (int i = start, j = start+1; i >= 0 && j < s.size(); --i, ++j) {
            if (s[i] != s[j]) break;
            l2 += 2;
        }
        if (l1 > l2) return {start-l1/2, l1};
        else return {start-l2/2+1, l2};
    }
};


// Solution 2 : dp, O(n^2)
// dp[i][j] = dp[i+1][j-1] if s[i] == s[j], else = 0;
class Solution2 {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        int maxi = 0, maxl = 1;
        for (int i = 0; i < n; ++i) dp[i][i] = true;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i+len-1 < n; ++i) {
                const int j = i+len-1;
                if (len == 2) dp[i][j] = s[i] == s[j];
                else dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                if (dp[i][j]) {
                    maxi = i;
                    maxl = len;
                }
            }
        }
        return s.substr(maxi, maxl);
    }
};


// Solution 3 : Manacher's Algorithm, O(n)
// http://www.cnblogs.com/Lyush/p/3221503.html
class Solution {
public:
    string preProcess(string& s) {
        string t = "$#";
        for (int i = 0; i < (int)s.size(); ++i) t += s.substr(i, 1) + "#";
        return t;
    }
    string longestPalindrome_n(string s) {
        if (s.size() < 2) return s;
        string t = preProcess(s);
        int n = t.size();
        vector<int> p(n, 0);
        int mx = 0, id = 0;
        for (int i = 1; i < n; ++i) {
            p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;
            while (t[i+p[i]] == t[i-p[i]]) ++p[i];
            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
        }
        int maxLen = 0, center = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                center = i;
            }
        }
        return s.substr(center/2 - maxLen/2, maxLen-1);
    }
};

int main() {
    Solution_2 s2;
    cout << s2.longestPalindrome("aaa") << endl;
    return 0;
}
