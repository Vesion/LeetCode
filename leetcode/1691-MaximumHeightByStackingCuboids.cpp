#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 3D variant of LIS, similar to 354-RussianDollEnvelopes
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& v : cuboids) sort(v.begin(), v.end());
        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) dp[i] = cuboids[i][2];
        int res = dp[0];
        for (int i = 1; i < n; ++i) {
            const auto& v1 = cuboids[i];
            for (int j = i-1; j >= 0; --j) {
                const auto& v2 = cuboids[j];
                if (v2[0] <= v1[0] && v2[1] <= v1[1] && v2[2] <= v1[2]) {
                    dp[i] = max(dp[i], dp[j]+v1[2]);
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};

int main() {
}
