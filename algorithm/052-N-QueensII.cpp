#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        dfs(0, 0, 0, (1<<n)-1, res);
        return res;
    }

    void dfs(int row, int ld, int rd, int board, int& res) {
        if (row == board) {
            ++res;
            return;
        }
        int valid = board & ~(row|ld|rd);
        while (valid) {
            int pos = valid & -valid;
            dfs(row|pos, (ld|pos)<<1, (rd|pos)>>1, board, res);
            valid -= pos;
        }

    }
};

int main() {
    Solution s;
    return 0;
}

