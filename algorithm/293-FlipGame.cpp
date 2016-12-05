#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        int n = s.size();
        if (n < 2) return {};
        vector<string> res;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '+' && s[i-1] == '+') {
                s[i] = s[i-1] = '-';
                res.push_back(s);
                s[i] = s[i-1] = '+';
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

