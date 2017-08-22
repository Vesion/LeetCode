#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

using row = vector<int>;
using matrix = vector<row>;

void print(matrix& m) {
    for (auto i : m) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
}


// 90 cloclwise
matrix rotate_90(matrix& m) {
    int n = m.size();
    matrix r = m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            r[i][j] = m[n-j-1][i];
    return r;
}

// 90 clockwise with 4 submatrixes
matrix rotate_block_90(matrix& m) {
    int n = m.size();
    matrix r = m;
    for (int i = 0; i < n/2; ++i) for (int j = 0; j < n/2; ++j) r[i][j] = m[i+n/2][j];
    for (int i = 0; i < n/2; ++i) for (int j = 0; j < n/2; ++j) r[i][j+n/2] = m[i][j];
    for (int i = 0; i < n/2; ++i) for (int j = 0; j < n/2; ++j) r[i+n/2][j+n/2] = m[i][j+n/2];
    for (int i = 0; i < n/2; ++i) for (int j = 0; j < n/2; ++j) r[i+n/2][j] = m[i+n/2][j+n/2];
    return r;
}

void dfs(matrix& m, int n) {
    if (n == 1) return;
    if (n%2) {
        matrix minM = m;
        matrix tmpM = m;
        for (int i = 0; i < 3; ++i) {
            tmpM = rotate_90(tmpM);
            if (tmpM < minM) minM = tmpM;
        }
        m = minM;
    } else {
        matrix top_left(n/2, row(n/2));
        for (int i = 0; i < n/2; ++i) for (int j = 0; j < n/2; ++j) top_left[i][j] = m[i][j];
        dfs(top_left, n/2);
        matrix top_right(n/2, row(n/2));
        for (int i = 0; i < n/2; ++i) for (int j = 0; j < n/2; ++j) top_right[i][j] = m[i][j+n/2];
        dfs(top_right, n/2);
        matrix bottom_left(n/2, row(n/2));
        for (int i = 0; i < n/2; ++i) for (int j = 0; j < n/2; ++j) bottom_left[i][j] = m[i+n/2][j];
        dfs(bottom_left, n/2);
        matrix bottom_right(n/2, row(n/2));
        for (int i = 0; i < n/2; ++i) for (int j = 0; j < n/2; ++j) bottom_right[i][j] = m[i+n/2][j+n/2];
        dfs(bottom_right, n/2);

        for (int i = 0; i < n/2; ++i) for (int j = 0; j < n/2; ++j) m[i][j] = top_left[i][j];
        for (int i = 0; i < n/2; ++i) for (int j = 0; j < n/2; ++j) m[i][j+n/2] = top_right[i][j];
        for (int i = 0; i < n/2; ++i) for (int j = 0; j < n/2; ++j) m[i+n/2][j] = bottom_left[i][j];
        for (int i = 0; i < n/2; ++i) for (int j = 0; j < n/2; ++j) m[i+n/2][j+n/2] = bottom_right[i][j];

        matrix minM = m;
        matrix tmpM = m;
        for (int i = 0; i < 3; ++i) {
            tmpM = rotate_block_90(tmpM);
            if (tmpM < minM) minM = tmpM;
        }
        m = minM;
    }
}


int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        matrix a(n, row(n)), b(n, row(n));
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> b[i][j];
        dfs(a, n);
        dfs(b, n);

        if (a == b) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
