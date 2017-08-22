#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// similar to 01-knapsack
class Solution {
public:
    int backPack(int m, vector<int> A) {
        if (A.empty() || m == 0) return 0;
        int n = A.size();
        vector<int> dp(m+1);
        for (int i = 0; i < n; ++i) {
            for (int j = m; j >= A[i]; --j)
                dp[j] = max(dp[j], dp[j-A[i]]+A[i]);
        }
        return dp[m];
    }
};

int main() {
    Solution s;
    cout << s.backPack(10, {3, 4, 8, 5}) << endl;
    return 0;
}
