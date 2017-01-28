#include <iostream>
#include <vector>
#include <string>
using namespace std;


// Solution 1: extend from each position, O(n^2)
// traverse the whole string, start finding the palindrome from each char (extend to left and right), get the longest substr
class Solution_1 {
public:
    string findPalindrome(string s, int l, int r) {
        int n = s.size();
        while (l >= 0 && r < n && s[l] == s[r]) {
            --l;
            ++r;
        }
        return s.substr(l + 1, r - l - 1);
    }

    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        string longest, str;
        for (int i = 0; i < (int)s.size() - 1; i++) {
            str = findPalindrome(s, i, i);
            if (str.size() > longest.size())
                longest = str;

            str = findPalindrome(s, i, i + 1);
            if (str.size() > longest.size())
                longest = str;
        }
        return longest;
    }
};


// Solution 2 : dp, O(n^2)
// dp[i][j] = dp[i+1][j-1] if s[i] == s[j], else = 0;
class Solution_2 {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return s;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) dp[i][i] = true;
        int start = 0, len = 1;
        for (int k = 2; k <= n; ++k) {
            for (int i = 0; i+k-1 < n; ++i) {
                int j = i+k-1;
                if (s[i] == s[j] && (i+1 > j-1 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if (j-i+1 > len) { len = j-i+1; start = i; }
                }
            }
        }
        return s.substr(start, len);
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
