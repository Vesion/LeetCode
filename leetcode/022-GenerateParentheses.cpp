#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Catalan number
// https://en.wikipedia.org/wiki/Catalan_number
// C0 = 1, Cn+1 = sum(Ci * Cn-i), i in [0, n]

// recursive
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        vector<string> res;
        for (int i = 0; i < n; ++i) {
            const auto r1 = generateParenthesis(i);
            const auto r2 = generateParenthesis(n-1-i);
            for (const string& s1 : r1) {
                for (const string& s2 : r2) {
                    res.push_back(s1 + "(" + s2 + ")");
                }
            }
        }
        return res;
    }
};

// iterative
class Solution_2 {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp;
        dp.push_back({""});
        for (int i = 1; i <= n; ++i) {
            vector<string> r;
            for (int j = 0; j < i; ++j) {
                for (string& left : dp[j]) {
                    for (string& right : dp[i-1-j]) {
                        r.push_back("(" + left + ")" + right);
                    }
                }
            }
            dp.push_back(r);
        }
        return dp.back();
    }
};

// generate one by one
class Solution_3 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, 0, "", res);
        return res;
    }

    // need left '('s and right ')'s
    void dfs(int left, int right, string path, vector<string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(path);
            return;
        }
        if (left) dfs(left-1, right+1, path+"(", res); // a '(' must match a ')'
        if (right) dfs(left, right-1, path+")", res); // match
    }
};


int main() {
    return 0;
}

