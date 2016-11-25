#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (char c : s) {
            res = res * 26 + (c-'A') + 1;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.titleToNumber("AA") << endl;
    return 0;
}

