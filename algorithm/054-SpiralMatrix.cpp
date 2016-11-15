#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        vector<int> res;
        int br = 0, er = matrix.size()-1; // begin row and end row
        int bc = 0, ec = matrix[0].size()-1; // begin col and end col

        while (true) {
            for (int j = bc; j <= ec; ++j) res.push_back(matrix[br][j]); // right
            if (++br > er) break;

            for (int i = br; i <= er; ++i) res.push_back(matrix[i][ec]); // down
            if (bc > --ec) break;

            for (int j = ec; j >= bc; --j) res.push_back(matrix[er][j]); // left
            if (br > --er) break;

            for (int i = er; i >= br; --i) res.push_back(matrix[i][bc]); // up
            if (++bc > ec) break;
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

