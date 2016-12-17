#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        if (t.empty()) return false;
        int i = 0;
        for (int j = 0; j < (int)t.size(); ++j) {
            if (s[i] == t[j]) ++i;
        }
        return i == (int)s.size();
    }
};

int main() {
    Solution s;
    return 0;
}

