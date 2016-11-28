#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() > t.size()) return isOneEditDistance(t, s); // s <= t
        int m = s.size(), n = t.size();
        if (n-m > 1) return false;
        if (m == 0) return n == 1;

        bool one = false;
        for (int i = 0, j = 0; i < m && j < n; ++i, ++j) {
            if (s[i] != t[j]) {
                if (one) return false;
                if (n > m) {
                    if (s[i] == t[j+1]) ++j;
                    else return false;
                }
                one = true;
            }
        }
        return one || (n > m);
    }
};

int main() {
    Solution s;
    cout << s.isOneEditDistance("a", "ac") <<endl;
    return 0;
}
