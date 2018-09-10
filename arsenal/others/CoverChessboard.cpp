#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Problem:
// Give a chessboard size of 2^n*2^n, there exists a special grid in it
// Use any 'L' graphs to cover the chessboard except the special grid. The 'L' graph can be transformed into other directions.
// Out put the cover solution.

// Solution:
// Divide and conquer

const int MAX = 100;
int board[MAX][MAX]; // the board
int id = 1; // id of L graph

void cover(int top, int left, int x, int y, int n) {
    if (n == 1) return;
    int t = id++; // get new id
    int m = n/2; // divide current board into 4 subboards with size of n/2

    // for each of 4 subboards, first check if (x, y) is in it
    //      if in, solve it recursively
    //      if not in, cover the corner grid first, then solve it recursively


    if (x < top+m && y < left+m) cover(top, left, x, y, m);
    else {
        board[top+m-1][left+m-1] = t; 
        cover(top, left, top+m-1, left+m-1, m);
    }

    if (x < top+m && y >= left+m) cover(top, left+m, x, y, m);
    else {
        board[top+m-1][left+m] = t;
        cover(top, left+m, top+m-1, left+m, m);
    }

    if (x >= top+m && y < left+m) cover(top+m, left, x, y, m);
    else {
        board[top+m][left+m-1] = t;
        cover(top+m, left, top+m, left+m-1, m);
    }

    if (x >= top+m && y >= left+m) cover(top+m, left+m, x, y, m);
    else {
        board[top+m][left+m] = t;
        cover(top+m, left+m, top+m, left+m, m);
    }
}


int main() {
    int n; // 2^n is the size of board
    int x, y; // position of special grid
    cin >> n;
    cin >> x >> y;
    memset(board, 0, sizeof board);
    n = 1 << n;
    cover(0, 0, x, y, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
    return 0;
}
