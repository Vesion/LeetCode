#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// A hard dp problem :(
// https://discuss.leetcode.com/topic/30431/easiest-java-solution-with-explanations

// buy[i] = max(buy[i-1], sell[i-2] - prices[i]);   
// sell[i] = max(sell[i-1], buy[i-1] + prices[i]);

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int b0 = -prices[0], b1 = -prices[0];
        int s0 = 0, s1 = 0, s2 = 0;

        for (int i = 1; i < n; ++i) {
            b1 = max(b0, s0 - prices[i]);
            s2 = max(s1, b0 + prices[i]);
            b0 = b1, s0 = s1, s1 = s2;
        }
        return  s2;
    }
};

int main() {
    Solution s;
    vector<int> p = {1,2,3,0,2};
    cout << s.maxProfit(p) << endl;
    return 0;
}

