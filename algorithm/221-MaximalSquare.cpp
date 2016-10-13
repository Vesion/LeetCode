#include <iostream>
#include <vector>
using namespace std;

// a very good dp problem

// dp[i][j] represents the the maximal size of the square that can be achieved at point (i,j). (not area, but size, area = size*size)
//      dp[0][j] = matrix[0][j]
//      dp[i][0] = matrix[i][0]
//      dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1


// Soltuion 1 : O(n^2) space
int maximalSquare_n2(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int maxsize = 0;

    for (int j = 0; j < n; ++j) {
        dp[0][j] = matrix[0][j] - '0';
        maxsize = max(maxsize, dp[0][j]);
    }
    for (int i = 0; i < m; ++i) {
        dp[i][0] = matrix[i][0] - '0';
        maxsize = max(maxsize, dp[i][0]);
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] == '1') {
                dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
                maxsize = max(maxsize, dp[i][j]);
            }
        }
    }
    return maxsize * maxsize;
}


// Solution 1 v2 : O(2*n) space
int maximalSquare_2n(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    vector<int> pre(m, 0), cur(m, 0);
    int maxsize = 0;

    for (int i = 0; i < m; ++i) {
        pre[i] = matrix[i][0] - '0';
        maxsize = max(maxsize, pre[i]);
    }
    for (int j = 1; j < n; ++j) {
        cur[0] = matrix[0][j] - '0';
        maxsize = max(maxsize, cur[0]);
        for (int i = 1; i < m; ++i) {
            if (matrix[i][j] == '1') {
                cur[i] = min(min(cur[i-1], pre[i]), pre[i-1]) + 1;
                maxsize = max(maxsize, cur[i]);
            }
        }
        pre = cur;
        fill_n(cur.begin(), m, 0);
    }
    return maxsize * maxsize;
}


// Solution 1 v3 : O(n) space
int maximalSquare_n(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();
    vector<int> cur(m+1, 0);
    int maxsize = 0;

    int pre = 0;
    for (int j = 0; j < n; ++j) {
        for (int i = 1; i <= m; ++i) {
            int temp = cur[i];
            if (matrix[i-1][j] == '1') {
                cur[i] = min(min(cur[i-1], cur[i]), pre) + 1;
                maxsize = max(maxsize, cur[i]);
            } else
                cur[i] = 0;
            pre = temp;
        }
    }
    return maxsize * maxsize;
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '1', '0', '1'}, 
        {'1', '1', '0', '1'},
        {'1', '1', '1', '1'},
    };
    cout << maximalSquare_n2(matrix) << endl;
    cout << maximalSquare_2n(matrix) << endl;
    cout << maximalSquare_n(matrix) << endl;

    return 0;
}
