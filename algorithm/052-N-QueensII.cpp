#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        return dfs(0, 0, 0, (1<<n)-1);
    }
    
    int dfs(int row, int ld, int rd, int board) {
        if (row == board) return 1;
        int res = 0;
        int valid = board & ~(row|ld|rd);
        while (valid) {
            int pos = valid & -valid;
            res += dfs(row|pos, (ld|pos)<<1, (rd|pos)>>1, board);
            valid -= pos;
        }
        return res;
    }
};


int main() {
    return 0;
}
