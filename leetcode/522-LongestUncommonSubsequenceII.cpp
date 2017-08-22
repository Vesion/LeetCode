#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string& s1, const string& s2) { return s1.size() > s2.size(); });
        int n = strs.size();
        for (int i = 0; i < n; ++i) {
            bool f = false;
            for (int j = 0; j < n; ++j) {
                if (i != j && isSubsequence(strs[j], strs[i])) { f = true; break; }
            }
            if (!f) return strs[i].size();
        }
        return -1;
    }
    
    bool isSubsequence(string& a, string& b) {
        int i = 0;
        for (char& c : a) if (c == b[i]) ++i;
        return i == (int)b.size();
    }
};


int main() {
    return 0;
}
