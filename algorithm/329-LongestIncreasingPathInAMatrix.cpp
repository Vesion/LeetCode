#include <iostream>
#include <vector>
using namespace std;

int go[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Solution 0 : brute-force, TLE
int dfs(vector<vector<int>>& matrix, int m, int n, int r, int c, vector<vector<bool>>& visited) {
    visited[r][c] = true;
    int result = 1;
    for (int d = 0; d < 4; ++d) {
        int x = r+go[d][0], y = c+go[d][1];
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
        if (matrix[x][y] <= matrix[r][c]) continue;
        result = max(result, dfs(matrix, m, m, r+go[d][0], c+go[d][1], visited)+1);
    }
    visited[r][c] = false;
    return result;
}

int longestIncreasingPath_bf(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    int result = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            result = max(result, dfs(matrix, m, n, i, j, visited));
        }
    }
    return result;
}


// Solution 1 : memorization, 95ms
// Actually, we do not need visited[m][n] array, because the path we are processing is increasing, so it won't revisit a smaller number which has been visited.
// Use a memo to cache subpathes' result.
int dfs(vector<vector<int>>& matrix, int m, int n, int i, int j, vector<vector<int>>& memo) {
    if (memo[i][j]) return memo[i][j];
    int result = 1;
    for (int d = 0; d < 4; ++d) {
        int x = i + go[d][0], y = j + go[d][1];
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
        result = max(result, dfs(matrix, m, n, x, y, memo) + 1);
    }
    memo[i][j] = result;
    return result;
}

int longestIncreasingPath_memo(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    int result = 1;
    vector<vector<int>> memo(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) result = max(result, dfs(matrix, m, n, i, j, memo));
    return result;
}


int main() {
    vector<vector<int>> matrix = { 
        { 9,9,4 },
        { 6,6,8 },
        { 2,1,1 }
    };
    cout << longestIncreasingPath_bf(matrix) << endl;
    cout << longestIncreasingPath_memo(matrix) << endl;
    return 0;
}
