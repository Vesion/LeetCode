#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    bool nums[10];
    for (int i = 0; i < 9; ++i) {
        memset(nums, false, 10);
        for (int j = 0; j < 9; ++j) { // check each line
            char c = board[i][j];
            if (c != '.') {
                if (nums[c - '0']) return false;
                nums[c - '0'] = true;
            }
        }
        memset(nums, false, 10);
        for (int j = 0; j < 9; ++j) { // check each column
            char c = board[j][i];
            if (c != '.') {
                if (nums[c - '0']) return false;
                nums[c - '0'] = true;
            }
        }
    }
    for (int i = 0; i < 9; i += 3) { // check each sub-box
        for (int j = 0; j < 9; j += 3) {
            memset(nums, false, 10);
            for (int p = i; p < i + 3; ++p) {
                for (int q = j; q < j +3; ++q) {
                    char c = board[p][q];
                    if (c != '.') {
                        if (nums[c - '0']) return false;
                        nums[c - '0'] = true;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    return 0;
}
