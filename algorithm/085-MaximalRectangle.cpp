#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n, 0);
        vector<int> l(n, 0); // max left bound in current height
        vector<int> r(n, n); // min right bound in current height
        // in each row, when arrive i, we have h[i] and [ l[i], r[i] ), area = h[i] * (r[i]-l[i])
        int res = 0;

        for (int i = 0; i < m; ++i) {
            int left = 0, right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    h[j]++;
                    l[j] = max(l[j], left); // max between pre row and current row
                } else {
                    left = j+1;
                    h[j] = 0; l[j] = 0; r[j] = n;
                }
            }

            for (int j = n-1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    r[j] = min(r[j], right); // min between pre row and current row
                    res = max(res, h[j] * (r[j]-l[j]));
                } else {
                    right = j;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

