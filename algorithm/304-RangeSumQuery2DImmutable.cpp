#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        sums.resize(m+1, vector<int>(n+1, 0));

        int row_sum = 0;
        for (int i = 0; i < m; ++i) {
            row_sum = 0;
            for (int j = 0; j < n; ++j) {
                row_sum += matrix[i][j];
                sums[i+1][j+1] = sums[i][j+1] + row_sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] + sums[row1][col1] - sums[row2+1][col1] - sums[row1][col2+1];
    }
};



int main() {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix numMatrix(matrix);
    cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
    cout << numMatrix.sumRegion(1, 1, 2, 2) << endl;
    cout << numMatrix.sumRegion(1, 2, 2, 4) << endl;
    return 0;
}
