#include <iostream>
#include <vector>
using namespace std;

int d[8][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

// Solution 0 : use a copy board, O(mn) time, O(mn) space
void gameOfLife_copy(vector<vector<int>>& board) {
    if (board.empty()) return;
    vector<vector<int>> old = board;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int lives = 0;
            for (int k = 0; k < 8; ++k) {
                if (i+d[k][0] >= 0 && i+d[k][0] < m && j+d[k][1] >= 0 && j+d[k][1] < n)
                    lives += old[i+d[k][0]][j+d[k][1]];
            }
            if (old[i][j]) board[i][j] = (lives == 2 || lives == 3) ? 1 : 0;
            else board[i][j] = lives == 3 ? 1 : 0;
        }
    }
}


// Solution 1 : bitmap, O(2*mn) time, O(1) space
// How to solve it in-place? The key is to find 'some place' to store the new states. Note that each cell is 0 or 1, it uses only lowest 1 bit, so the rest (32-1) bits are available, and we only need to use the second bit to store the new state. Finally, shift all values one bit to the right.
void gameOfLife(vector<vector<int>>& board) {
    if (board.empty()) return;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int lives = -board[i][j];
            // because the loop below counts live neighbors and itself all 9 cells, so here we init lives with -board[i][j] to make lives end up with only live neighbors
            for (int x = max(i-1, 0); x <= min(i+1, m-1); ++x)
                for (int y = max(j-1, 0); y <= min(j+1, n-1); ++y)
                    lives += (board[x][y] & 1); // do not forget & 1, because the old state is on the 1-bit
            cout << lives << endl;
            if ((lives | board[i][j]) == 3) // use a trick here, it equls to : if ((board[i][j] == 1 && (count == 2 || count == 3)) || (board[i][j] == 0 && count == 3))
                board[i][j] |= 2; // 1-bit store old state, 2-bit store new state
        }
    }
    for (auto &i : board) for (auto &j : i) j >>= 1; // update
}


int main() {
    vector<vector<int>> board = {
        {1, 1},
        {1, 0}
    };
    gameOfLife(board);
    for (auto i : board) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
