#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        vector<vector<int>> res;
        res.push_back({1});
        for (int i = 2; i <= numRows; ++i) {
            vector<int> row(i, 0);
            for (int j = 0; j < i; ++j) {
                if (j-1 < 0 || j >= (int)res[i-2].size()) row[j] = 1;
                else row[j] = res[i-2][j-1] + res[i-2][j];
            }
            res.push_back(row);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

