#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Solution 1 : use std::unordered_set
bool containsNearbyDuplicate_set(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return false;
    if (k <= 0) return false;
    if (k >= n) k = n-1;
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        if (s.find(nums[i]) != s.end()) return true;
        if (s.size() == k) s.erase(nums[i-k]);
        s.insert(nums[i]);
    }
    return false;
}


// Solution 2 : use std::unordered_map
bool containsNearbyDuplicate_map(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0) return false;
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
        if (m[nums[i]] && i+1 - m[nums[i]] <= k) return true;
        m[nums[i]] = i+1;
    }
    return false;
}

int main() {
    vector<int> nums = {1, 1};
    cout << containsNearbyDuplicate_set(nums, 2) << endl;
    cout << containsNearbyDuplicate_map(nums, 2) << endl;
    return 0;
}
