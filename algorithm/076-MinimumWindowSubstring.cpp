#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Sliding window
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (char c : t) m[c]++;
        int i = 0, j = 0, c = t.size();
        int len = INT_MAX, start = 0;
        while (j < (int)s.size()) {
            if (m[s[j++]]-- > 0) --c;
            while (c == 0) { // find a valid substring
                if (j-i < len) { len = j-i; start = i; }
                if (m[s[i++]]++ == 0) ++c; // shrink window to turn it into an invalid substring
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};


int main() {
    Solution s;
    return 0;
}

