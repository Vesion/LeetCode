#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

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
