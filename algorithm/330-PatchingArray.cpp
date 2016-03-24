#include <iostream>
#include <vector>
using namespace std;

// greedy
// Let miss be the smallest sum in [0,n] that we might be missing. Meaning we already know we can build all sums in [0,miss). Then if we have a number num <= miss in the given array, we can add it to those smaller sums to build all sums in [0,miss+num). If we don't, then we must add such a number to the array, and it's best to add miss itself, to maximize the reach.
int minPatches(vector<int>& nums, int n) {
    long long miss = 1, i = 0;
    int result = 0;
    while (miss <= n) {
        if (i < nums.size() && miss >= nums[i]) {
            miss += nums[i++];
        } else {
            ++result;
            miss += miss;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 31, 33};
    cout << minPatches(nums, INT_MAX) << endl;
    return 0;
}
