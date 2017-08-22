#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dp, O(n^2) time, O(n) space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle.back(); // init with the last row
        for (int i = n-2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};


int main() {
    return 0;
}
