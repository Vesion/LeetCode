#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int br = 0, er = n-1, bc = 0, ec = n-1;
        vector<vector<int>> res(n, vector<int>(n));
        int num = 0;
        while (true) {
            for (int j = bc; j <= ec; ++j) res[br][j] = ++num;
            if (++br > er) break;

            for (int i = br; i <= er; ++i) res[i][ec] = ++num;
            if (bc > --ec) break;

            for (int j = ec; j >= bc; --j) res[er][j] = ++num;
            if (br > --er) break;

            for (int i = er; i >= br; --i) res[i][bc] = ++num;
            if (++bc > ec) break;
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

