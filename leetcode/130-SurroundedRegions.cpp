#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// First check four borders, mark 'O's start from border as 'C', then flip 'X' to 'O', lastly flip 'C' back to 'O'

// Solution 1 : DFS, use a trick to avoid stack overflow
class Solution {
public:
    int m, n;

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0); // or bfs
            if (board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m-1][j] == 'O') dfs(board, m-1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'C') board[i][j] = 'O';
            }
        }
    }

    // Here is a trick, we use 'if (i > 1)' instead of 'if (i > 0)' to avoid stack overflow (runtime error) in LC
    // Refer to the comment in this thred:
    // https://discuss.leetcode.com/topic/17224/a-really-simple-and-readable-c-solution-only-cost-12ms/8
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = 'C';
            if (i > 1) dfs(board, i-1, j);
            if (i+1 < m) dfs(board, i+1, j);
            if (j > 1) dfs(board, i, j-1);
            if (j+1 < n) dfs(board, i, j+1);
        }
    }
};


// Solution 2 : BFS
class Solution2 {
public:
    int m, n;

    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') bfs(board, 0, j);
            if (board[m-1][j] == 'O') bfs(board, m-1, j);
        }
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') bfs(board, i, 0);
            if (board[i][n-1] == 'O') bfs(board, i, n-1);
        }
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'B') board[i][j] = 'O';
            else if (board[i][j] == 'O') board[i][j] = 'X';
        }
    }

    void bfs(vector<vector<char>>& board, int i, int j) {
        constexpr int go[5] = {1, 0, -1, 0, 1};
        queue<pair<int,int>> q;
        q.push({i,j});
        board[i][j] = 'B';
        while (!q.empty()) {
            auto s = q.front(); q.pop();
            int x = s.first, y = s.second;
            for (int d = 0; d < 4; ++d) {
                int nx = x+go[d], ny = y+go[d+1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (board[nx][ny] != 'O') continue;
                q.push({nx,ny});
                board[nx][ny] = 'B';
            }
        }
    }
};


// Union find
class Solution3 {
public:
    int m, n;
    vector<int> root;
    int find(int x) {
        if (x != root[x]) root[x] = find(root[x]);
        return root[x];
    }
    void link(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) root[ry] = rx;
    }
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        root.resize(m*n, -1);
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'O') root[i*n+j] = i*n+j;
        }
        constexpr int go[5] = {-1, 0, 1, 0, -1};
        unordered_set<int> side;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'X') continue;
            int x = i*n+j;
            for (int d = 0; d < 4; ++d) {
                int ni = i+go[d], nj = j+go[d+1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if (board[ni][nj] == 'X') continue;
                link(x, ni*n+nj);
            }
        }
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'X') continue;
            if (i == 0 || i == m-1 || j == 0 || j == n-1) side.insert(find(i*n+j));
        }

        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'X') continue;
            if (!side.count(find(i*n+j))) board[i][j] = 'X';
        }
    }
};


int main() {
    return 0;
}

