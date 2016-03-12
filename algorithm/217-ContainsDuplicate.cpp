#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Solution 1 : use std::sort, O(nlgn) time, O(1) space
bool containsDuplicate_sort(vector<int>& nums) {
    if (nums.empty()) return false;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); ++i)
        if (nums[i] == nums[i-1]) return true;
    return false;
}


// Solution 2 : use std::unordered_set, O(n) time, O(n) space
bool containsDuplicate_set(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    return s.size() != nums.size();
}


// Solution 3 : use std::unordered_map, O(n) time, O(n) space
bool containsDuplicate_map(vector<int>& nums) {
    unordered_map<int, int> m;
    for (auto & num : nums) {
        if (m[num]) return true;
        ++m[num];
    }
    return false;
}

int main() {
    vector<int> nums = {1, 3, 7, 10, 2, 3};
    cout << containsDuplicate_sort(nums) << endl;
    cout << containsDuplicate_set(nums) << endl;
    cout << containsDuplicate_map(nums) << endl;
    return 0;
}
