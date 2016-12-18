#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        if (s.empty()) return 0;
        vector<int> m(128, 0);
        for (char c : s) m[c]++;
        int res = 0;
        for (int i : m) res += (i&1) ? ((res&1) ? i-1 : i) : i;
        return res;
    }
};


int main() {
    Solution s;
    cout << s.longestPalindrome("abccccdd");
    return 0;
}
