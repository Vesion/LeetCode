#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    int go[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int m, n;
    vector<vector<int>> memo;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        m = matrix.size(), n = matrix[0].size();
        memo.resize(m, vector<int>(n, 0));
        int res = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, i, j));
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (memo[i][j]) return memo[i][j];
        int len = 1;
        for (int d = 0; d < 4; ++d) {
            int ni = i+go[d][0], nj = j+go[d][1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || matrix[ni][nj] <= matrix[i][j]) continue;
            len = max(len, dfs(matrix, ni, nj)+1);
        }
        memo[i][j] = len;
        return len;
    }
};

int main() {
    Solution s;
    vector<vector<int>> m1 = {
        { 9,9,4 },
        { 6,6,8 },
        { 2,1,1 }
    };
    cout << s.longestIncreasingPath(m1) << endl;
    return 0;
}

