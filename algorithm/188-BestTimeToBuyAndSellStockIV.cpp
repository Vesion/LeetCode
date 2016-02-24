#include <iostream>
#include <vector>
using namespace std;

// a really hard problem!
//
// http://blog.csdn.net/linhuanmars/article/details/23236995
// 核心思想还是dp，不过这题需要两个数组：
//      一个记录全局最优，表示当前到达第i天可以进行最多j次交易，最高的利润是多少，用global[i][j]表示
//      一个记录局部最优，表示当前到达第i天可以进行最多j次交易，并且最后一次交易在当天卖出，最高利润是多少，用local[i][j]表示
// 因此，可得递推式：
//
//      global[i][j] = max( local[i][j], global[i-1][j] )
//      local[i][j]  = max( global[i-1][j-1] + max(diff, 0), local[i-1][j] + diff )
//
// global的递推式很好理解，就是取“当前局部最好的”和“过去全局最好的”中较大的那个，因为如果第j次交易发生在当天，那么最高利润肯定在“当前局部最好的”里，否则就肯定在“过去全局最好的”里；
// local的递推式不太好理解，首先看第一个量，是到第i-1天最多j-1次交易的全局最好加上今天的第j次交易所赚的钱（注意这里max(diff,0)表示今天可能亏钱，如果diff<0，则表示昨天买今天卖会亏钱，这样就不符合最优，所以就今天买今天卖，就是0，这样既保证了到第i天最多j次交易，且第j次卖出是在第i天，又保证了最优），第二个量是到第i-1天最多j交易的局部最好，现在变成不在第i-1天卖出而是第i天卖出，不管今天卖出是亏是赚（即不论diff是否大于0）都要加上diff，否则就不满足local[i][j]是到第i天进行第j次交易的定义了。

// dp, O(n*k) time, O(k) space
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();

    // if k > n/2, it means that I can buy in every day and sell out next day
    // then the problem is same to 122, k is not a restriction any more
    if (k > n/2) {
        int result = 0;
        for (int i = 1; i < n; ++i)
            if (prices[i] > prices[i-1]) result += (prices[i] - prices[i-1]);
        return result;
    }

    // else, dp
    vector<int> local(k+1, 0);
    vector<int> global(k+1, 0);
    for (int i = 1; i < n; ++i) {
        int diff = prices[i] - prices[i-1];
        for (int j = k; j >= 1; --j) {
            local[j] = max(global[j-1] + max(diff, 0), local[j] + diff);
            global[j] = max(local[j], global[j]);
        }
    }
    return global[k];
}

int main() {
    vector<int> prices {1, 2, 3, 4, 5};
    cout << maxProfit(2, prices) << endl;;
    return 0;
}
