#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int m, n;
    vector<int> findBall(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) res[i] = get(grid, i);
        return res;
    }

    int get(vector<vector<int>>& grid, int j) {
        for (int i = 0; i < m; ++i) {
            if (grid[i][j] == 1) {
                if (j == n-1 || grid[i][j+1] == -1) return -1;
                ++j;
            }
            if (grid[i][j] == -1) {
                if (j == 0 || grid[i][j-1] == 1) return -1;
                --j;
            }
            if (i == m-1) return j;
        }
        return -1;
    }
};

int main() {

}
