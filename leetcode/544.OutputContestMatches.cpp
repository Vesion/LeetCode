#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string findContestMatch(int n) {
        vector<string> res(n);
        for (int i = 0; i < n; ++i) res[i] = to_string(i+1);
        while (n > 1) {
            for (int i = 0; i < n/2; ++i) {
                res[i] = "(" + res[i] + "," + res[n-1-i] + ")";
            }
            n /= 2;
        }
        return res[0];
    }
};


int main() {
    Solution s;
    cout << s.findContestMatch(4) << endl;
    return 0;
}
