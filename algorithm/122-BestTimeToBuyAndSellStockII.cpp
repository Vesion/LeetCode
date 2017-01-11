#include <iostream>
#include <vector>
using namespace std;

// greedy, find all increasing stocks
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
