#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// after sorting, this problem is equal to two-sum
// for subarray [i,...,j] which a[i] + a[j] <= target, subsets of [i+1,...,j], 2^(j-i) count for result
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        constexpr int kMod = 1e9+7;

        // need pre-calculate pow(2, i) with mod
        vector<long long> pow(n);
        pow[0] = 1;
        for (int i = 1; i < n; ++i) {
            pow[i] = (pow[i-1] * 2) % kMod;
        }

        for (int i = 0, j = n-1; i <= j; ) {
            if (nums[i] + nums[j] > target) --j;
            else {
                res = (res + pow[j-i]) % kMod;
                ++i;
            }
        }
        return res;
    }
};

int main() {
}
