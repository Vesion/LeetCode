#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to 'Max 2 subarrys sum'
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        vector<int> leftMax(n, 0), rightMax(n, 0);

        int minPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i-1], prices[i]-minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        int maxPrice = prices[n-1];
        for (int i = n-2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i+1], maxPrice-prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
            res = max(res, leftMax[i]+rightMax[i]);
        return res;
    }
};


int main() {
    return 0;
}
