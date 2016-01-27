#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    if (n == 0)
        return matrix;

    int num = 1;
    int bx = 0, ex = n - 1;
    int by = 0, ey = n - 1;
    for (;;) {
        for (int j = bx; j <= ex; ++j)
            matrix[by][j] = num++;
        if (++by > ey) break;

        for (int i = by; i <= ey; ++i)
            matrix[i][ex] = num++;
        if (--ex < bx) break;

        for (int j = ex; j >= bx; --j)
            matrix[ey][j] = num++;
        if (--ey < by) break;

        for (int i = ey; i >= by; --i)
            matrix[i][bx] = num++;
        if (++bx > ex) break;
    }
    return matrix;
}

int main() {
    for (auto i : generateMatrix(1)) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
