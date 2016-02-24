#include <iostream>
#include <vector>
using namespace std;

// 相当于在一个数组中找出差值最大的两个数，且小数要在大数前面


// greedy (or dp)
// 一边遍历一边得到当前最小的入价和最高的利润
int maxProfit(vector<int>& prices) {
    int result = 0;
    int minprice = INT_MAX; // the price I buy in
    for (int i = 0; i < prices.size(); ++i) { // when I sell stock in day i
        result = max(result, prices[i] - minprice); // compare today's profit with last day's, choose the bigger one, dp
        minprice = min(minprice, prices[i]); // maintain the minimum price I bought in (do not care the day, because when it must be before the selling day, greedy)
    }
    return result;
}

int main() {
    vector<int> prices = {1, 4, 10, 11};
    cout << maxProfit(prices) << endl;
    return 0;
}
