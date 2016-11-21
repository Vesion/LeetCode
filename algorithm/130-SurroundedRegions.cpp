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
class Solution_2 {
public:
    int m, n;
    queue<pair<int,int>> q;

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') bfs(board, i, 0);
            if (board[i][n-1] == 'O') bfs(board, i, n-1);
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') bfs(board, 0, j);
            if (board[m-1][j] == 'O') bfs(board, m-1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'C') board[i][j] = 'O';
            }
        }
    }

    void bfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = 'C';
        q.push(make_pair(i, j));
        while (!q.empty()) {
            auto next = q.front();
            q.pop();
            int i = next.first, j = next.second;
            //board[i][j] = 'C'; // don't update here, it's too late, update it before enque

            if (i > 0 && board[i - 1][j] == 'O'){
                board[i - 1][j] = 'C';
                q.push(make_pair(i - 1, j));
            }
            if (i<m - 1 && board[i + 1][j] == 'O'){
                board[i+1][j] = 'C';
                q.push(make_pair(i + 1, j));
            }
            if (j>0 && board[i][j - 1] == 'O'){
                board[i][j-1] = 'C';
                q.push(make_pair(i, j - 1));
            }
            if (j < n - 1 && board[i][j + 1] == 'O'){
                board[i][j+1] = 'C';
                q.push(make_pair(i, j + 1));
            }
        }
    }
};


int main() {
    return 0;
}

