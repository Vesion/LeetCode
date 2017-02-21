#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int c;
        int res = 0;
        for (int i = 0; i < m; ++i) {
            c = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'W') c = 0;
                else if (grid[i][j] == 'E') ++c;
                else dp[i][j] += c;
            }

            c = 0;
            for (int j = n-1; j >= 0; --j) {
                if (grid[i][j] == 'W') c = 0;
                else if (grid[i][j] == 'E') ++c;
                else dp[i][j] += c;
            }
        }

        for (int j = 0; j < n; ++j) {
            c = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 'W') c = 0;
                else if (grid[i][j] == 'E') ++c;
                else dp[i][j] += c;
            }

            c = 0;
            for (int i = m-1; i >= 0; --i) {
                if (grid[i][j] == 'W') c = 0;
                else if (grid[i][j] == 'E') ++c;
                else dp[i][j] += c;
                res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};


int main() {
    Solution s;
    vector<vector<char>> g = {
        {'0', 'E', '0', '0'},
        {'E', '0', 'W', 'E'},
        {'0', 'E', '0', '0'},
    };
    cout << s.maxKilledEnemies(g) << endl;
    return 0;
}
