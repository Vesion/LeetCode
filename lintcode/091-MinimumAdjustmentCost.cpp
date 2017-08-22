#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// hard
// dp[i][v] means the minimal cost when adjust A[i] to v
// dp[i][v] = min { dp[i-1][v'] + |A[i]-v|, |v'-v|<=target }
class Solution {
public:
    int MinAdjustmentCost(vector<int> A, int target) {
        if (A.empty()) return 0;
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(101, 0));

        for (int v = 1; v <= 100; ++v)
            dp[0][v] = abs(v-A[0]);

        for (int i = 1; i < n; ++i) {
            for (int v = 1; v <= 100; ++v) {
                dp[i][v] = INT_MAX;
                for (int k = 1; k <= 100; ++k) {
                    if (abs(v-k) > target) continue;
                    dp[i][v] = min(dp[i][v], dp[i-1][k]+abs(v-A[i]));
                }
            }
        }

        int result = INT_MAX;
        for (int v = 1; v <= 100; ++v)
            result = min(result, dp[n-1][v]);
        return result;
    }
};

int main() {
    Solution s;
    cout << s.MinAdjustmentCost({1, 4, 2, 3}, 1) << endl;
    return 0;
}
