#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty() || numRows <= 1) return s;
        string res;
        for (int i = 0; i < numRows; ++i) {
            bool down = true;
            int j = i;
            while (j < (int)s.size()) {
                res += s[j];
                if (down || i == 0) j += 2*(numRows-1-i);
                if (!down || i == numRows-1) j += 2*i;
                down = !down;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.convert("abcd", 1) << endl;
    return 0;
}

