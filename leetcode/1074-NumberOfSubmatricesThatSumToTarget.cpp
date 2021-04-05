#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// DP, O(n^3), based on 1D variant 560-SubarraySumEqualsK
// Similar to 1504-CountSubmatricesWithAllOnes
class Solution {
public:
    int m, n;
    vector<vector<int>> row;

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        row.resize(m, vector<int>(n+1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row[i][j+1] = row[i][j] + matrix[i][j];
            }
        }

        int res = 0;
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = j1; j2 < n; ++j2) {
                res += sum1d(j1, j2, target);
            }
        }
        return res;
    }

    int sum1d(int j1, int j2, int target) {
        unordered_map<int,int> dp;
        dp[0] = 1;
        int sum = 0, res = 0;
        for (int i = 0; i < m; ++i) {
            sum += row[i][j2+1]-row[i][j1];
            if (dp.count(sum-target)) res += dp[sum-target];
            ++dp[sum];
        }
        return res;
    }
};

int main() {

}
