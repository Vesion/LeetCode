#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.empty() && t.empty()) return true;
        int n = s.size();
        vector<int> m1(128, 0), m2(128, 0);
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = m2[t[i]] = i+1;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout <<s.isIsomorphic("ab", "aa") << endl;
    cout <<s.isIsomorphic("ab", "ca") << endl;
    return 0;
}

