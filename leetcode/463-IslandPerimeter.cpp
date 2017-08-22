#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    res += 4;
                    if (i-1 >= 0 && grid[i-1][j] == 1) res -= 2;
                    if (j-1 >= 0 && grid[i][j-1] == 1) res -= 2;
                }
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
