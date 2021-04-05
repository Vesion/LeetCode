#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;

// Solution 1 : deque, O(m*n) time O(n) space
class Solution_1 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;

        deque<pair<int,int>> q;
        q.push_back({0, 0});
        bool downup = true;

        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                int i, j;
                if (downup) { i = q.front().first, j = q.front().second; q.pop_front(); }
                else { i = q.back().first, j = q.back().second; q.pop_back(); }

                res.push_back(matrix[i][j]);

                if (downup) {
                    if (j == 0) if (i+1 < m) q.push_back({i+1, j});
                    if (j+1 < n) q.push_back({i, j+1});
                } else {
                    if (i == 0) if (j+1 < n) q.push_front({i, j+1});
                    if (i+1 < m) q.push_front({i+1, j});
                }
            }
            downup = !downup;
        }
        return res;
    }
};


// Solution 2 : change direction when out of border, O(m*n) time O(1) space
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res(m*n);
        constexpr int go[2][2] = {{-1,1}, {1,-1}};
        int i = 0, j = 0, d = 0;
        for (int k = 0; k < m*n; ++k) {
            res[k] = mat[i][j];
            i += go[d][0];
            j += go[d][1];
            // NOTE the order
            if (i >= m) { i = m-1; j += 2; d = 1-d; }
            if (j >= n) { j = n-1; i += 2; d = 1-d; }
            if (i < 0) { i = 0; d = 1-d; }
            if (j < 0) { j = 0; d = 1-d; }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
    };
    auto r = s.findDiagonalOrder(matrix);
    for (auto& e : r) cout << e << " "; cout << endl;
    return 0;
}
