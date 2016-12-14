#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

// This problem is the 2D version of 'Max subarray sum no larger than k'

// O(n^2 * mlogm)
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();

        int res = INT_MIN;
        for (int c1 = 0; c1 < n; ++c1) {
            vector<int> rowsums(m, 0);
            for (int c2 = c1; c2 < n; ++c2) {
                for (int i = 0; i < m; ++i) rowsums[i] += matrix[i][c2];
                set<int> colsums;
                colsums.insert(0);
                int colsum = 0, local = INT_MIN;
                for (int sum : rowsums) {
                    colsum += sum;
                    auto it = colsums.lower_bound(colsum-k);
                    if (it != colsums.end()) 
                        local = max(local, colsum-*it);
                    colsums.insert(colsum);
                }
                res = max(res, local);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

