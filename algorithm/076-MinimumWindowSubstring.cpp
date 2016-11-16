#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (char& c : t) m[c]++;
        int i = 0, j = 0; // window bound
        int start = -1, len = INT_MAX; // result's start and length
        int count = 0; // count characters in t
        while (j < (int)s.size()) {
            if (m[s[j++]]-- > 0) ++count; // extend window
            while (count == (int)t.size()) { // if find a valid window, shrink until it turns to invalid
                if (j-i < len) { // find the shortest window in all valid windows
                    len = j-i;
                    start = i;
                }
                if (m[s[i++]]++ == 0) --count; // shrink window
            }
        }
        return start == -1 ? "" : s.substr(start, len);
    }
};

int main() {
    Solution s;
    return 0;
}

