#include <iostream>
#include <vector>
using namespace std;

//
// classical back tracking solution
//

bool isValid(vector<vector<char>>& board, int x, int y) {
    for (int i = 0; i < 9; ++i) // check line
        if (i != y && board[x][y] == board[x][i])
            return false;
    for (int j = 0; j < 9; ++j) // check column
        if (j != x && board[x][y] == board[j][y])
            return false;
    for (int i = 3*(x/3); i < 3*(x/3+1); ++i) { // check sub-box
        for (int j = 3*(y/3); j < 3*(y/3+1); ++j) {
            if ((i != x || j != y) && board[i][j] == board[x][y])
                return false;
        }
    }
    return true;
}

bool solved(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') {
                for (int k = 0; k < 9; ++k) { // choose a number from 1...9
                    board[i][j] = '1' + k; // attempt to fill k
                    if (isValid(board, i, j) && solved(board)) // if valid, start to recurse filling
                        return true; // if all cells filled and valid, solved
                    board[i][j] = '.'; // if k is invalid, erase cell
                }
                return false; // if all 1...9 are invalid, start to back track
            }
        }
    }
    return true; // never reach here
}

void solveSudoku(vector<vector<char>>& board) {
    solved(board);
}

int main() {
    return 0;
}
