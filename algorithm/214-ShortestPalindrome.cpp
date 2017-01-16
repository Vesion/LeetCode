#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Learn to use 'Prefix Array in KMP Algorithm', O(n)
//      Step 1: we construct a new string t with (s) + '#' + (reversed s)
//      Step 2: calculate the prefix array of t
//      Step 3: watch the last value, it shows us the largest suffix of the reversed string that matches the prefix of the original string.
//      Step 4: add the first k characters of the reversed string to the original string, where k is a difference between original string size and the prefix function for the last character of a constructed string.
//      e.g. s is "abacdef", so t is "abacdef#fedcaba", the last value of prefux array is 3, so the result is "fedcabacdef"
//
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;

        string rs = s;
        reverse(rs.begin(), rs.end());
        string t = s + "#" + rs; // why use '#' to split them, think about case "aaaa"
        int m = t.size();
        vector<int> prefix(m, 0);

        int j = 0;
        for (int i = 1; i < m; ++i) {
            while (j > 0 && t[i] != t[j]) j = prefix[j-1];
            if (t[i] == t[j]) ++j;
            prefix[i] = j;
        }
        return rs.substr(0, n-prefix[m-1]) + s;
    }
};

int main() {
    Solution s;
    return 0;
}

