#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;
        vector<int> dp(n, 0);
        int res = 0;
        for (int i = 2; i < n; ++i) {
            if (A[i]-A[i-1] == A[i-1]-A[i-2])
                dp[i] = dp[i-1] + 1;
            res += dp[i];
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> A = {1, 2, 3, 4, 5};
    cout << s.numberOfArithmeticSlices(A) <<endl;
    return 0;
}
