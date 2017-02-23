#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : 2D binary indexed tree
class NumMatrix {
private:
    vector<vector<int>> nums, sums;
    int m, n;
    
    void add(int row, int col, int val) {
        for (int i = row+1; i <= m; i += (i & -i)) {
            for (int j = col+1; j <= n; j += (j & -j)) {
                sums[i][j] += val;
            }
        }
    }
    
    int query(int row, int col) {
        int res = 0;
        for (int i = row+1; i > 0; i -= (i & -i)) {
            for (int j = col+1; j > 0; j -= (j & -j)) {
                res += sums[i][j];
            }
        }
        return res;
    }
    
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty()) return;
        m = matrix.size(), n = matrix[0].size();
        nums = matrix;
        sums.resize(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) add(i, j, nums[i][j]);
    }
    
    void update(int row, int col, int val) {
        add(row, col, val-nums[row][col]);
        nums[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(row2, col2) - query(row1-1, col2) - query(row2, col1-1) + query(row1-1, col1-1);
    }
};


int main() {
    return 0;
}
