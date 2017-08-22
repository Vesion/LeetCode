#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> m(128, 0);
        for (char c : s) m[c]++;
        int d[10] = {0};
        d[0] = m['z'];
        d[2] = m['w'];
        d[4] = m['u'];
        d[6] = m['x'];
        d[8] = m['g'];

        d[3] = m['h'] - d[8];
        d[5] = m['f'] - d[4];

        d[7] = m['v'] - d[5];
        d[1] = m['o'] - d[2] - d[4] - d[0];
        d[9] = m['i'] - d[5] - d[6] - d[8];

        string res;
        for (int i = 0; i < 10; ++i) res += d[i] > 0 ? string(d[i], '0'+i) : "";
        return res;
    }
};

int main() {
    Solution s;
    cout << s.originalDigits("fviefuro") <<endl;
    return 0;
}

