#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if (words.empty()) return true;
        int m = words.size();
        for (int i = 0; i < m; ++i) {
            int n = words[i].size();
            for (int j = 0; j < n; ++j)
                if (j >= m || i >= (int)words[j].size() || words[i][j] != words[j][i]) return false;
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
