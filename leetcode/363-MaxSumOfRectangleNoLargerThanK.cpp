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
            vector<int> nums(m, 0);
            for (int c2 = c1; c2 < n; ++c2) {
                for (int i = 0; i < m; ++i) nums[i] += matrix[i][c2];
                set<int> sums;
                sums.insert(0);
                int sum = 0;
                for (int num : nums) {
                    sum += num;
                    auto it = sums.lower_bound(sum-k);
                    if (it != sums.end()) res = max(res, sum-*it);
                    sums.insert(sum);
                }
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
