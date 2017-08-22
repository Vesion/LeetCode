#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        for (int i = 1; i < (int)s.size(); ++i) {
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
    return 0;
}

