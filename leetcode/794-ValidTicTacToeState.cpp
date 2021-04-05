#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int turn = 0;
        int row[3] = {}, col[3] = {};
        int di = 0, ad = 0;
        for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 'X') {
                ++turn;
                ++row[i]; ++col[j];
                if (i == j) ++di;
                if (i + j == 2) ++ad;
            } else if (board[i][j] == 'O') {
                --turn;
                --row[i]; --col[j];
                if (i == j) --di;
                if (i + j == 2) --ad;
            }
        }
        bool xwin = row[0] == 3 || row[1] == 3 || row[2] == 3 ||
                    col[0] == 3 || col[1] == 3 || col[2] == 3 ||
                    di == 3 || ad == 3;
        bool owin = row[0] == -3 || row[1] == -3 || row[2] == -3 ||
                    col[0] == -3 || col[1] == -3 || col[2] == -3 ||
                    di == -3 || ad == -3;
        return (xwin && !owin && turn == 1) ||
               (owin && !xwin && turn == 0) ||
               (!xwin && !owin && (turn == 1 || turn == 0));
    }
};

int main() {
}
