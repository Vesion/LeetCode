#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
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
    return 0;
}
