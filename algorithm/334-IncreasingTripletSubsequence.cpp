#include <iostream>
#include <vector>
using namespace std;

// Solution 1 : similar to LIS O(nlgn) time, O(1) space
bool increasingTriplet_lis(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return false;
    vector<int> lis;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
        if (it == lis.end()) lis.push_back(nums[i]);
        else *it = nums[i]; 
        if (lis.size() >= 3) return true;
    }
    return false;
}


// Solution 2 : greedy, O(n) time, O(1) space
bool increasingTriplet(vector<int>& nums) {
    int small = INT_MAX, middle = INT_MAX;
    for (auto & num : nums) {
        if (num <= small) small = num; // keep small always smallest
        else if (num <= middle) middle = num; // num is between (small, middle], narrow our interval
        else return true; // num is greater than middle, so "small, large, num" is our want result
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3};
    cout << increasingTriplet(nums) << endl;
    return 0;
}
