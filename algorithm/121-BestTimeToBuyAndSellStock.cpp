#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to 'MaxSubarrySum'
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp = INT_MAX;
        int res = 0;
        for (int i = 0; i < (int)prices.size(); ++i) {
            minp = min(minp, prices[i]);
            res = max(res, prices[i]-minp);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

