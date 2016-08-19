#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(); 
        int result = INT_MIN;

        for (int c1 = 0; c1 < n; ++c1) { // as problem says, the number of rows is larger than the number of columns, so we scan columns
            vector<int> rowsum(m, 0);
            for (int c2 = c1; c2 < n; ++c2) {
                for (int r = 0; r < m; ++r)
                    rowsum[r] += matrix[r][c2];

                set<int> cums;
                cums.insert(0);
                int cum = 0, local = INT_MIN;
                for (auto &sum : rowsum) {
                    cum += sum;
                    auto it = cums.lower_bound(cum-k);
                    if (it != cums.end()) 
                        local = max(local, cum-*it);
                    cums.insert(cum);
                }
                result = max(result, local);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {0, -2, 3}
    };
    cout << s.maxSumSubmatrix(matrix, 2) << endl;;
    return 0;
}
