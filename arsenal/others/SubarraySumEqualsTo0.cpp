#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
using namespace std;

// Given an integer array, find a subarray where the sum of numbers is 0 (or `target`). 
// Return the index of the first number and the index of the last number, {0, 0} if does not exists.


// use hashmap to store {sum, i}, where sum is accumulating from index 0 to i
// check sum each time if it has occurred, if occurred, the sum of subarray from last occurred to this is 0
vector<int> subarraySum(vector<int>& nums) {
    int n = nums.size();
    map<int, int> m;
    m[0] = -1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        if (m.count(sum)) return {m[sum]+1, i};
        m[sum] = i;
    }
    return {0, 0};
}

int main() {
    vector<int> nums = {3, 1, -1, -1, 2};
    auto r = subarraySum(nums);
    cout << r[0] << " " << r[1] << endl;
    return 0;
}
