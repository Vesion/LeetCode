#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) return 0;
        int n = triangle.size();
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = (int)triangle[i].size()-1; j >= 0; --j) {
                if (j == 0) dp[j] += triangle[i][j];
                else if (j == (int)triangle[i].size()-1) dp[j] = dp[j-1] + triangle[i][j];
                else dp[j] = min(dp[j-1], dp[j]) + triangle[i][j];
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution s;
    return 0;
}
