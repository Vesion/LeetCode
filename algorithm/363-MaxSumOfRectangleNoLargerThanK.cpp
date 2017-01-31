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
            vector<int> colsums(m, 0);
            for (int c2 = c1; c2 < n; ++c2) {
                for (int i = 0; i < m; ++i) colsums[i] += matrix[i][c2];
                set<int> rowsums;
                rowsums.insert(0);
                int rowsum = 0, local = INT_MIN;
                for (int& colsum : colsums) {
                    rowsum += colsum;
                    auto it = rowsums.lower_bound(rowsum-k);
                    if (it != rowsums.end()) local = max(local, rowsum-*it);
                    rowsums.insert(rowsum);
                }
                res = max(res, local);
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
