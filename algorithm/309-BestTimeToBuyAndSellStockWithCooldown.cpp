#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// A hard dp problem :(
// https://discuss.leetcode.com/topic/30431/easiest-java-solution-with-explanations

// buy[i] means reach ith day, the last operation is buy (not neccessarily buy right on ith day)
//      buy[i] = max(buy[i-1], sell[i-2] - prices[i]);   // buy in day-i, or not
// sell[i] ditto
//      sell[i] = max(sell[i-1], buy[i-1] + prices[i]);  // sell in day-i, or not

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> buy(n, 0), sell(n, 0);

        buy[0] = -prices[0]; 
        buy[1] = max(buy[0], -prices[1]);

        sell[0] = 0; 
        sell[1] = max(0, prices[1]-prices[0]);

        for (int i = 2; i < n; ++i) {
            buy[i] = max(buy[i-1], sell[i-2]-prices[i]);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
        }
        return sell[n-1];
    }
};


int main() {
    return 0;
}

