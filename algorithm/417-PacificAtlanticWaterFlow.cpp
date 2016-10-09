#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : naive dfs
class Solution {
private:
    int go[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> state; // 1 for Pacific, 2 for Atlantic, 3 for both
    int m, n;
    vector<pair<int, int>> result;

public:
    void dfs(vector<vector<int>>& matrix, int i, int j, int preH, int preS) {
        if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] < preH || (state[i][j] & preS) == preS)
            return;
        state[i][j] |= preS;
        if (state[i][j] == 3) result.emplace_back(make_pair(i, j));
        for (int d = 0; d < 4; ++d) 
            dfs(matrix, i+go[d][0], j+go[d][1], matrix[i][j], state[i][j]);
    }

    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        m = matrix.size(), n = matrix[0].size();
        state.resize(m, vector<int>(n, false));

        for (int i = 0; i < m; ++i) {
            dfs(matrix, i, 0, INT_MIN, 1);
            dfs(matrix, i, n-1, INT_MIN, 2);
        }
        for (int j = 0; j < n; ++j) {
            dfs(matrix, 0, j, INT_MIN, 1);
            dfs(matrix, m-1, j, INT_MIN, 2);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4 ,4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };
    auto r = s.pacificAtlantic(matrix);
    for (auto& e : r) cout << e.first << " " <<e.second << endl;; cout << endl; 
    return 0;
}
