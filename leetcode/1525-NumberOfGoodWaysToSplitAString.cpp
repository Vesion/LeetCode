#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int numSplits(string s) {
        int lm[26] = {0}, rm[26] = {0};
        int l = 0, r = 0;
        for (char c : s) {
            if (rm[c-'a']++ == 0) ++r;
        }

        int res = 0, n = s.size();
        for (int i = 0; i < n-1; ++i) {
            char c = s[i];
            if (lm[c-'a']++ == 0) ++l;
            if (--rm[c-'a'] == 0) --r;
            if (l == r) ++res;
        }
        return res;
    }
};

int main() {

}
