#include <iostream>
#include <vector>
using namespace std;

// O(n^2), O(n^2), not in-place
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int rows = matrix.size();
    if (rows == 0)
        return result;
    int columns = matrix[0].size();

    vector<vector<bool>> flag(rows, vector<bool>(columns, false));

    int r = 0, c = 0;
    while (r >= 0 && r < rows && c >= 0 && c < columns && flag[r][c] == false) {
        while (c < columns && !flag[r][c]) {
            result.push_back(matrix[r][c]);
            flag[r][c] = true;
            ++c;
        }
        --c, ++r;
        while (r < rows && !flag[r][c]) {
            result.push_back(matrix[r][c]);
            flag[r][c] = true;
            ++r;
        }
        --r, --c; 
        while (c >= 0 && !flag[r][c]) {
            result.push_back(matrix[r][c]);
            flag[r][c] = true;
            --c;
        }
        ++c, --r;
        while (r >= 0 && !flag[r][c]) {
            result.push_back(matrix[r][c]);
            flag[r][c] = true;
            --r;
        }
        ++r, ++c;
    }
    return result;
}

// O(n^2), O(1), in-place
vector<int> spiralOrder_inplace(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty())
        return result;
    // sentinels
    int bx = 0, ex = matrix[0].size() - 1;
    int by = 0, ey = matrix.size() - 1;
    for (;;) {
        for (int j = bx; j <= ex; ++j)
            result.push_back(matrix[by][j]);
        if (++by > ey) break;

        for (int i = by; i <= ey; ++i)
            result.push_back(matrix[i][ex]);
        if (bx > --ex) break;

        for (int j = ex; j >= bx; --j)
            result.push_back(matrix[ey][j]);
        if (by > --ey) break;

        for (int i = ey; i >= by; --i)
            result.push_back(matrix[i][bx]);
        if (++bx > ex) break;
    }
    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {7, 1, 1, 2, 3},
        {7, 1, 1, 2, 3},
    };
    for (auto i : spiralOrder_inplace(matrix)) {
        cout << i << " ";
    }
    return 0;
}
