#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& a, int k) {
        int m = a.size(), n = a[0].size();
        vector<vector<int>> sum(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; ++i) {
            int l = 0;
            for (int j = 1; j <= n; ++j) {
                l += a[i-1][j-1];
                sum[i][j] = sum[i-1][j] + l;
            }
        }
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int i1 = min(m, i+k), i0 = max(0, i-k-1);
                int j1 = min(n, j+k), j0 = max(0, j-k-1);
                res[i-1][j-1] = sum[i1][j1] - sum[i0][j1] - sum[i1][j0] + sum[i0][j0];
            }
        }
        return res;
    }
};

int main() {

}
