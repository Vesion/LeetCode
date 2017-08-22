#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {{false}};
        bool col[9][9] = {{false}};
        bool box[3][3][9] = {{false}};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    int n = c - '1';
                    if (row[i][n] || col[j][n] || box[i/3][j/3][n]) return false;
                    row[i][n] = col[j][n] = box[i/3][j/3][n] = true;
                }
            }
        }
        return true;
    }
};


int main() {
    return 0;
}

