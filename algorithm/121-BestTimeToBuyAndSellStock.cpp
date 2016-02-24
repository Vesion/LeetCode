#include <iostream>
#include <vector>
using namespace std;

// Solution 0 : brute-force, O(n^2) time, TLE
int maxProfit_n2(vector<int>& prices) {
    int result = 0;
    int n = prices.size();
    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n; ++j)
            if (prices[j] > prices[i]) result = max(result, prices[j]-prices[i]);
    return result;
}


// Solution 1 : greedy, O(n)
// 相当于在一个数组中找出差值最大的两个数，且小数要在大数前面
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
    cout << maxProfit_n2(prices) << endl;
    cout << maxProfit(prices) << endl;
    return 0;
}
