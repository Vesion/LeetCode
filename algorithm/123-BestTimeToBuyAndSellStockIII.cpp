#include <iostream>
#include <vector>
using namespace std;

// 这题跟122看上去只是略微差别，将任意多次交易改成了最多两次交易，但是如果套用122的思路，是得不到正确答案的。
// 因为122是典型的贪心策略，每来一个数，就去求到这天为止的最大利润，而不管前面最大利润是如何获取的，也不管后面会有怎样的价格。
//
// 所以本题需要换一种思路。
//
// 回过头来看看121，只允许一次交易的时候，我们能得到一串连续的数的最大利润，且能在O(n)时间完成，那么本题要两次交易，而且两次交易是不重叠的，顶多在第一次卖的那天再买进，所以在整个序列中必然会形成两个不相交的子串，
// 接下来就自然能想到将整个序列看成前后两个子串相连，用121中的方法求每个子串的最大利润再相加就是整个序列的最大利润，但是问题是如何知道两个子串的分隔点在哪，也就是说没有什么神奇的方法能快速找到这么一个点，将整个串分成前后两个子串，这两个子串的最大利润之和就是整个串的最大利润，所以只能一个一个遍历了。
// 问题又来了，如果暴力遍历，对每个点都左右子串求一遍最大利润，整个算法就是O(n^2)复杂度的，肯定不行，所以这里就有了dp的思想，我先从前往后遍历一遍，记录前缀子串[0...i]的最大利润p[i]，再从后往前遍历一遍，记录后缀子串[i...n]的最大利润s[i]，最后遍历这两个数组，max_profit = max{p[i]+s[n-i]}，就是要求的最大利润，整个算法需要O(3*n)时间。

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n < 2) return 0;
    vector<int> p(n, 0), s(n, 0);

    // get prefix subarray's maxprofit
    int min_price = prices[0];
    for (int i = 1; i < n; ++i) {
        p[i] = max(p[i-1], prices[i] - min_price);
        min_price = min(min_price, prices[i]);
    }

    // get suffix subarray's maxprofit
    int max_price = prices[n-1];
    for (int i = n-2; i >= 0; --i) {
        s[i] = max(0, max_price - prices[i]);
        max_price = max(max_price, prices[i]);
    }

    // get the total maxprofit
    int max_profit = 0;
    for (int i = 0; i < n; ++i)
        max_profit = max(max_profit, p[i] + s[i]);
    return max_profit;
}

int main() {
    vector<int> prices = {1, 2, 3, 4, 5, 6};
    cout << maxProfit(prices) << endl;
    return 0;
}
