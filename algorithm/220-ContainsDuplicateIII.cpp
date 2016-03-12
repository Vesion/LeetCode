#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Solution 1 : use std::set, O(n*lgk)
// very skillful, similiar to 219-ContainsDuplicateII solution 1
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int n = nums.size();
    if (n == 0) return false;
    if (k == 0) return false;
    if (k >= n) k = n-1;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        if (i > k) s.erase(nums[i-k-1]); // keep the set contains at most k numbers
        // |x-nums[i]| <= t --> -t <= x-nums[i] <= t
        auto pos = s.lower_bound(nums[i]-t); // -t <= x-nums[i] --> x >= nums[i]-t, the 'lower_bound' well played!
        if (pos != s.end() && *pos-nums[i] <= t) // x-nums[i] <= t
            return true;
        s.insert(nums[i]);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    cout << containsNearbyAlmostDuplicate(nums, 2, 1);
    return 0;
}
