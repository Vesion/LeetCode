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
        int start = 0, len = INT_MAX;
        while (j < (int)s.size()) {
            if (m[s[j++]]-- > 0) --c;
            while (c == 0) {
                if (j-i < len) { start = i, len = min(len, j-i); }
                if (m[s[i++]]++ == 0) ++c;
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};


int main() {
    return 0;
}

