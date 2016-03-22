#include <iostream>
#include <vector>
using namespace std;

// Well, how poor I am bad at DP! :(
// Let's learn from others.

// https://leetcode.com/discuss/72030/share-my-dp-solution-by-state-machine-thinking
// https://leetcode.com/discuss/71354/share-my-thinking-process
//
// buy[i] means before day i what is the maxProfit for any sequence end with buy.
// sell[i] means before day i what is the maxProfit for any sequence end with sell.
// rest[i] means before day i what is the maxProfit for any sequence end with rest.
//
//      buy[i]  = max(rest[i-1]-price, buy[i-1])        // buy stock at day i or not
//      sell[i] = max(buy[i-1]+price, sell[i-1])        // sell stock at day i or not
//      rest[i] = max(sell[i-1], buy[i-1], rest[i-1])   // rest at day i or not
//

// Solution 1 : O(n) space
int maxProfit_On(vector<int>& prices) {
    int n = prices.size();
    if (n < 2) return 0;
    vector<int> buy(n, 0), sell(n, 0), rest(n, 0);
    buy[0] = -prices[0], sell[0] = 0, rest[0] = 0;
    for (int i = 1; i < n; ++i) {
        buy[i] = max(rest[i-1]-prices[i], buy[i-1]);
        sell[i] = max(buy[i-1]+prices[i], sell[i-1]);
        rest[i] = sell[i-1];
    }
    return sell[n-1];
}


// due to buy[i] <= rest[i] and rest[i] <= sell[i], so the third equation is rest[i] = sell[i-1], and use it in above two:
//      
//      buy[i] = max(sell[i-2]-price, buy[i-1])
//      sell[i] = max(buy[i-1]+price, sell[i-1])
//
// Since states of day i relies only on i-1 and i-2 we can reduce the O(n) space to O(1). 

// Solution 1 v2 : O(1) space
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n < 2) return 0;
    int prev_buy, buy(-prices[0]), prev_sell(0), sell(0);
    for (auto & price : prices) {
        prev_buy = buy;
        buy = max(prev_sell-price, buy);
        prev_sell = sell;
        sell = max(prev_buy+price, sell);
    }
    return sell;
}

int main() {
    vector<int> prices = {2, 1, 4};
    cout << maxProfit_On(prices) << endl;
    cout << maxProfit(prices) << endl;
    return 0;
}
