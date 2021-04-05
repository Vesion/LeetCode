#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Divide and conquer
// First count each character's occurrence times, then split string with those smaller than k and recursive
class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.size(), k);
    }

    int helper(const string& s, int start, int end, int k) {
        int m[26] = {};
        for (int i = start; i < end; ++i) ++m[s[i]-'a'];
        int res = 0;
        for (int i = start; i < end; ) {
            if (m[s[i]-'a'] >= k) {
                int j = i;
                while (j < end && m[s[j]-'a'] >= k) ++j;
                if (i == start && j == end) return j-i;
                res = max(res, helper(s, i, j, k));
                i = j;
            } else {
                ++i;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.longestSubstring("aaabbb", 3) <<endl;
    return 0;
}

