#include <iostream>
#include <vector>
using namespace std;

// 相比于121，这题允许多次交易，所以就是找出数组中所有的递增段，把正差值全部加起来即可
// 又因为，例如[1, 2, 3, 4]，1近4出相当于1进2出，2进3出，3进4出，即4-1 == 2-1 + 3-2 + 4-3
// 所以只需要比较相邻的两个数即可
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < (int)prices.size(); ++i) {
            if (prices[i] > prices[i-1])
                res += prices[i]-prices[i-1];
        }
        return res;
    }
};


int main() {
    return 0;
}
