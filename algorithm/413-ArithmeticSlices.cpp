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
        vector<int> dp(n, 0); // dp[i] means the number of arithmetic slices ends with A[i]
        if (A[2]-A[1] == A[1]-A[0]) dp[2] = 1; // if the first three number is arithmetic or not
        int result = dp[2];
        for (int i = 3; i < n; ++i) {
            // if A[i-2], A[i-1], A[i] is arithmetic, then the number of arithmetic slices ends with A[i] (dp[i])
            // equals to 
            //      the number of arithmetic slices ends with A[i-1] (all those arithmetic slices append A[i] are also arithmetic)
            //      +
            //      A[i-2], A[i-1], A[i] (a brand new arithmetic slice)
            // so it is how dp[i] = dp[i-1] + 1 comes
            if (A[i]-A[i-1] == A[i-1]-A[i-2]) 
                dp[i] = dp[i-1] + 1;
            result += dp[i]; // accumulate all number of valid slices
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> A = {1, 2, 3, 4, 5};
    cout << s.numberOfArithmeticSlices(A) <<endl;
    return 0;
}
