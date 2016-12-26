#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Sliding window
// This problem is a bit of different with other sliding window's:
//      we move a fixed-size-window from left to right, use a counter to validate anagrams.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> m(128, 0);
        for (char c : p) m[c]++;
        int i = 0, j = 0, c = p.size();
        vector<int> res;
        while (j < (int)s.size()) {
            if (m[s[j++]]-- > 0) --c;
            if (c == 0) res.push_back(i);
            if (j-i == (int)p.size() && m[s[i++]]++ >= 0) ++c;
        }
        return res;
    }
};


int main() {
    Solution s;
    auto r = s.findAnagrams("abacbabc", "abc");
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
