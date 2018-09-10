#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// n*n square, 90 clockwise, in place
void rotate_inplace(vector<vector<int>>& square) {
    reverse(square.begin(), square.end()); // reverse up to down
    int n = square.size();
    for (int i = 0; i < n; ++i) // reverse with main-diagonal
        for (int j = 0; j < i; ++j)
            swap(square[i][j], square[j][i]);
}

// m*n rectangle, 90 cloclwise
vector<vector<int>> rotate_90(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> r(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            r[i][j] = matrix[m-j-1][i];
    return r;
}

// m*n rectangle, 90 cloclwise
vector<vector<int>> rotate_180(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> r(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            r[i][j] = matrix[m-i-1][n-j-1];
    return r;
}

// m*n rectangle, 90 cloclwise
vector<vector<int>> rotate_270(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> r(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            r[i][j] = matrix[j][n-i-1];
    return r;
}


int main() {
    vector<vector<int>> m = {
        {1, 2, 3},
        {4, 5, 6},
    };
    m = rotate_270(m);
    for (auto& i : m) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}
