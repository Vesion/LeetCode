#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        vector<double> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 0; i < prob.size(); ++i) {
            for (int j = min(i+1, target); j >= 0; --j) {
                dp[j] = dp[j]*(1-prob[i]) + (j == 0 ? 0 : dp[j-1]*prob[i]);
            }
        }
        return dp[target];
    }
};

int main() {
}
