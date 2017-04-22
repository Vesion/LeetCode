#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        int n = strs.size();
        char maxc = 0;
        for (int i = 0; i < n; ++i) {
            for (char& c : strs[i]) maxc = max(c, maxc);
            string t = strs[i]; reverse(t.begin(), t.end());
            strs[i] = max(t, strs[i]);
        }

        string res;
        for (int i = 0; i < n; ++i) {
            for (int loop = 0; loop < 2; ++loop) {
                for (int j = 0; j < (int)strs[i].size(); ++j) {
                    if (strs[i][j] == maxc) {
                        string r = strs[i].substr(j);
                        for (int k = 1; k < n; ++k) r += strs[(i+k)%n];
                        r += strs[i].substr(0, j);
                        res = max(res, r);
                    }
                }
                reverse(strs[i].begin(), strs[i].end());
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<string> strs = {"b", "z", "a", "bza"};
    cout << s.splitLoopedString(strs) << endl;
    return 0;
}
