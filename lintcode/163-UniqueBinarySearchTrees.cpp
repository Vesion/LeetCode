#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// classical Catalan Number problem

// Solution 1 : recursively (definition)
class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) return 1;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += numTrees(i) * numTrees(n-i-1);
        }
        return result;
    }
};


// Solution 2 : iteratively, dp
class Solution_dp {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 1);
        for (int i = 2; i <= n; ++i) {
            dp[i] = 0;
            for (int j = 0; j < i; ++j)
                dp[i] += dp[j] * dp[i-j-1];
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.numTrees(3) << endl;

    Solution_dp s2;
    cout << s2.numTrees(3) << endl;
    return 0;
}
