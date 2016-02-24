#include <iostream>
#include <vector>
using namespace std;

// 相当于在一个数组中找出差值最大的两个数，且小数要在大数前面


// greedy (or dp)
// 一边遍历一边得到当前最小的入价和最高的利润
int maxProfit(vector<int>& prices) {
    int result = 0, minprice = INT_MAX;
    for (int i = 0; i < prices.size(); ++i) {
        result = max(result, prices[i] - minprice);
        minprice = min(minprice, prices[i]);
    }
    return result;
}

int main() {
    vector<int> prices = {1, 4, 10, 11};
    cout << maxProfit(prices) << endl;
    return 0;
}
