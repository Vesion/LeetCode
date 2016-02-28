#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Solution 1 : brute-force bfs, O(n^2), TLE!
// 朴素暴力广搜，不考虑四条边，从内部开始若是O，就bfs判断是否在一个region里，如果是就把该region里的O变成X，效率低
struct Point {
    int X, Y;
    Point(int x, int y) : X(x), Y(y) {}
};

const int go[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

void solve_n2(vector<vector<char>>& board) {
    int m = board.size();
    if (m < 3) return;
    int n = board[0].size(); 
    if (n < 3) return;

    for (int i = 1; i < m-1; ++i) {
        for (int j = 1; j < n-1; ++j) {
            if (board[i][j] == 'X') continue;

            vector<vector<bool>> visited(m, (vector<bool>(n, false)));
            bool region = true;
            vector<Point> candidates;
            queue<Point> q;
            q.push(Point(j, i));
            while (!q.empty()) {
                auto point = q.front(); q.pop();
                visited[point.Y][point.X] = true;
                candidates.push_back(point);
                for (int d = 0; d < 4; ++d) {
                    int newX = point.X + go[d][0];
                    int newY = point.Y + go[d][1];
                    if (newX < 0 || newX >= n || newY < 0 || newY >= m) {
                        region = false;
                        continue;
                    }
                    if (visited[newY][newX]) continue;
                    if (board[newY][newX] == 'O') q.push(Point(newX, newY));
                }
            }
            if (region) {
                for (auto &p : candidates) {
                    board[p.Y][p.X] = 'X';
                }
            }

        }
    }
}


// Solution 2 : O(n)
// 因为只有最外面的0可以不在region里，所以从四条边开始dfs找出所有不在region里的O，记录下来，然后把其他所有0变成X，再把记录的O恢复

void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
    if (board[i][j] == 'O') {
        board[i][j] = '+';
        if (i > 1) dfs(board, i-1, j, m, n);
        if (j > 1) dfs(board, i, j-1, m, n);
        if (i+1 < m) dfs(board, i+1, j, m, m);
        if (j+1 < n) dfs(board, i, j+1, m, n);
    }
}

void solve(vector<vector<char>>& board) {
    int m = board.size();
    if (m < 3) return;
    int n = board[0].size(); 
    if (n < 3) return;

    for (int i = 0; i < m; ++i) {
        dfs(board, i, 0, m, n);
        dfs(board, i, n-1, m , n);
    }
    for (int j = 0; j < n; ++j) {
        dfs(board, 0, j, m, n);
        dfs(board, m-1, j, m, n);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == '+') board[i][j] = 'O';
        }
    }
}

int main() {
    vector<vector<char>> board = {
        {'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'},
    };
    //vector<vector<char>> board = {
        //{'X', 'X', 'X'},
        //{'X', 'O', 'X'},
        //{'X', 'X', 'X'},
    //};
    solve(board);
    for (auto & i : board) {
        for (auto & j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
