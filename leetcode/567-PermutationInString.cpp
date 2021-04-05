#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        int m[26] = {};
        for (char c : s1) ++m[c-'a'];
        int k = 0;
        for (int i = 0, j = 0; j < n2; ++j) {
            if (--m[s2[j]-'a'] >= 0) ++k;
            if (j-i+1 > n1 && ++m[s2[i++]-'a'] > 0) --k;
            if (k == n1) return true;
        }
        return false;
    }
};


int main() {
    return 0;
}
