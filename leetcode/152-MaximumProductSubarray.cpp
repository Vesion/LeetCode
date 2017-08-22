#include <iostream>
#include <vector>
using namespace std;

// similar to 053-MaximumSumSubarray
// but here we need to maintain 'max product' and 'min product'
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int maxp = 1, minp = 1;
        for (int& num : nums) {
            int tmaxp = maxp, tminp = minp;
            maxp = max(num, max(tmaxp*num, tminp*num));
            minp = min(num, min(tmaxp*num, tminp*num));
            res = max(res, maxp);
        }
        return res;
    }
};


int main() {
    return 0;
}
