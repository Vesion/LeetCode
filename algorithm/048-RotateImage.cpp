#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// a common solution, not in-place
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> c_matrix(n);
    copy(matrix.begin(), matrix.end(), c_matrix.begin());
    for (int i = 0; i < n / 2; ++i) {
        int ni = n - i * 2;
        for (int p = 0; p < ni; ++p) {
            matrix[i][i + p] = c_matrix[i + ni - 1 - p][i];
            matrix[i + p][i + ni - 1] = c_matrix[i][i + p];
            matrix[i + ni - 1][i + p] = c_matrix[i + ni - 1 - p][i + ni -1];
            matrix[i + p][i] = c_matrix[i + ni - 1][i + p];
        }
    }
}

// a much faster solution in-place
// 先沿着副对角线翻转一次，再沿着水平中线翻转一次
// 或者，先沿着水平中线翻转一次，再沿着主对角线翻转一次
void rotate_flip(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(matrix[i][j], matrix[n - i - 1][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2}, 
                                  {4, 5}, 
                                  };
    //rotate(matrix);
    rotate_flip(matrix);
    for (auto i : matrix) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
