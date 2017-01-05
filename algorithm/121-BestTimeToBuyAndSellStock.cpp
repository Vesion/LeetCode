#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dp, similar to 'MaxSubarrySum'
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, min_price = INT_MAX;
        for (int& price : prices) {
            res = max(res, price-min_price);
            min_price = min(min_price, price);
        }
        return res;
    }
};


int main() {
    return 0;
}

