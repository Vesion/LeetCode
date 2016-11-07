#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
#include <unordered_map> 
#include <unordered_set> 
using namespace std;

// dp[i][d] means the number of arithmetic subsequences ending with A[i], diff is d
// MLE in LC ?
class Solution_0 {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.empty()) return 0;
        int n = A.size();
        vector<unordered_map<long long, int>> dp(n);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                long long d = (long long)A[i] - A[j];
                dp[i][d]++;
                if (dp[j].count(d)) {
                    dp[i][d] += dp[j][d];
                    res += dp[j][d];
                }
            }
        }
        return res;
    }
};


// dp[i][d] means the number of arithmetic subsequences whose last but one integer is A[i]
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.empty()) return 0;
        int n = A.size();
        vector<unordered_map<long long, int >> dp(n);
        unordered_set<int> s(A.begin(), A.end());
        int res = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                long long d = (long long)A[i] - (long long)A[j];
                int tmp = dp[j].count(d) ? dp[j][d] : 0;
                if (tmp) res += tmp;
                if (s.count(A[i]+d)) dp[i][d] += 1 + tmp;
            }
        }
        return res;
    }
};

int main() {
    Solution_0 s0;
    Solution s;
    vector<int> a = {2, 4, 6,  8, 10};
    cout << s0.numberOfArithmeticSlices(a) << endl;
    cout << s.numberOfArithmeticSlices(a) << endl;
}

