#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> m(128, 0);
        for (char c : s) m[c]++;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (m[s[i]] == 1) return i;
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.firstUniqChar("aabccbd") <<endl;
    return 0;
}
