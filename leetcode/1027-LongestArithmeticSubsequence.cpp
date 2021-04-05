#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        vector<unordered_map<int,int>> dp(n);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int d = A[i] - A[j];
                if (dp[j].count(d)) dp[i][d] = max(dp[i][d], dp[j][d]+1);
                else dp[i][d] = 2;
                res = max(res, dp[i][d]);
            }
        }
        return res;
    }
};

int main() {

}