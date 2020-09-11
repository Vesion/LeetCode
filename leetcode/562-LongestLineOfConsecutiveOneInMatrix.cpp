#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// O(m*n) space
class Solution0 {
public:
    int go[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
    int longestLine(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int m = M.size(), n = M[0].size();
        vector<vector<array<bool,4>>> s(m, vector<array<bool,4>>(n));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 0) continue;
                for (int d = 0; d < 4; ++d) {
                    if (s[i][j][d]) continue;
                    s[i][j][d] = true;
                    int l = 1;
                    int ni = i, nj = j;
                    while (true) {
                        ni += go[d][0];
                        nj += go[d][1];
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n || M[ni][nj] == 0) break;
                        ++l;
                        s[ni][nj][d] = true;
                    }
                    res = max(res, l);
                }
            }
        }
        return res;
    }
};

// O(m+n) space
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size(), m = M[0].size();
        vector<int> v(m, 0), d(n+m-1, 0), ad(n+m-1, 0);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int h = 0;
            for (int j = 0; j < m; ++j) {
                if (M[i][j] == 1) {
                    ++h; ++v[j]; ++d[i+j]; ++ad[i+m-j-1];
                } else {
                    h = v[j] = d[i+j] = ad[i+m-j-1] = 0;
                }
                res = max(res, max(max(h, v[j]), max(d[i+j], ad[i+m-j-1])));
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
