#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if (words.empty()) return true;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            string col;
            for (int j = 0; j < n; ++j) {
                if (i < (int)words[j].size()) col += words[j][i];
            }
            if (col != words[i]) return false;
        }
        return true;
    }
};


int main() {
    Solution s;
    vector<string> words = { 
        "abcd",
        "bnrt",
        "cra",
        "dt"
    };
    cout << s.validWordSquare(words) <<endl;
    return 0;
}
