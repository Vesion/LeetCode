#include <iostream>
#include <vector>
using namespace std;

// use O(m+n) space
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<bool> rows(m, false), columns(n, false);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                rows[i] = columns[j] = true;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (rows[i] == true)
            for (int p = 0; p < n; ++p) matrix[i][p] = 0;
    }
    for (int j = 0; j < n; ++j) {
        if (columns[j] == true)
            for (int q = 0; q < m; ++q) matrix[q][j] = 0;
    }
}

// try to use O(1) space, but wrong!
// 想先用INT_MIN标记0，然后最后再换成0，但是若原矩阵中就存在INT_MIN肯定出错
//void setZeroes_wrong(vector<vector<int>>& matrix) {
    //int m = matrix.size(), n = matrix[0].size();
    //for (int i = 0; i < m; ++i) {
        //for (int j = 0; j < n; ++j) {
            //if (matrix[i][j] == 0) {
                //for (int p = 0; p < n; ++p) {
                    //if (matrix[i][p] != 0) matrix[i][p] = INT_MIN;
                //}
                //for (int q = 0; q < m; ++q) {
                    //if (matrix[q][j] != 0) matrix[q][j] = INT_MIN;
                //}
            //}
        //}
    //}
    //for (int i = 0; i < m; ++i)
        //for (int j = 0; j < n; ++j)
            //matrix[i][j] = (matrix[i][j] == INT_MIN) ? 0 : matrix[i][j];
//}

// O(1) space
// 回到O(m+n)方法，在此基础上不用额外空间，可以借助第0行第0列来暂时存储信息
void setZeroes_1(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool row0 = false, col0 = false;
    for (int i = 0; i < m; ++i) // check if 0th col has 0
        if (matrix[i][0] == 0) col0 = true;
    for (int j = 0; j < n; ++j) // check if 0th row has 0
        if (matrix[0][j] == 0) row0 = true;
    for (int i = 1; i < m; ++i) // use 0th row and 0th col to store infos
        for (int j = 1; j < n; ++j)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    for (int i = 1; i < m; ++i) // use stored infos to set 0s
        for (int j = 1; j < n; ++j)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
    if (col0) // set 0th col
        for (int i = 0; i < m; ++i)
            matrix[i][0] = 0;
    if (row0) // set 0th row
        for (int j = 0; j < n; ++j)
            matrix[0][j] = 0;
}

int main() {
    vector<vector<int>> matrix ={
        { 0,0,0,5 },
        { 4,3,1,4 },
        { 0,1,1,4 },
        { 1,2,1,3 },
        { 0,0,1,1 }};
    setZeroes_1(matrix);
    for (auto i : matrix) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
