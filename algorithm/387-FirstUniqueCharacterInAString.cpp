#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int m[26];
        fill(m, m+26, -1);

        for (int i = 0; i < (int)s.size(); ++i) {
            int c = s[i] - 'a';
            if (m[c] == -1) m[c] = i;
            else m[c] = -2;
        }
        int result = INT_MAX;
        for (auto i : m) {
            if (i >= 0) result = min(i, result);
        }
        return result != INT_MAX ? result : -1;
    }
};

int main() {
    Solution s;
    cout << s.firstUniqChar("aabccbd") <<endl;
    return 0;
}
