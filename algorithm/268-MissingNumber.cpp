#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Solution 1 : theoretical sum minus real sum, O(n) time
int missingNumber_sum(vector<int>& nums) {
    long long sum = accumulate(nums.begin(), nums.end(), 0);
    long long n = nums.size();
    return (n*(n+1)>>1) - sum;
}


// Solution 2 : bit manipulation, XOR, O(n) time
// e.g. 0 1 2 3 4 5  index
//      0 1   3 4 5  number (missing 2)
//      0 0 2 0 0 0  index ^ number (result is 2)
int missingNumber_bit(vector<int>& nums) {
    int n = nums.size();
    int result = n;
    for (int i = 0; i < n; ++i) {
        result ^= i;
        result ^= nums[i];
    }
    return result;
}


// Solution 3 : sort and binary search, O(nlgn) time
int missingNumber_bs(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right-left)/2;
        if (nums[mid] > mid) right = mid;
        else left = mid+1;
    }
    return left;
}


int main() {
    vector<int> nums = {0, 1};
    cout << missingNumber_sum(nums) << endl;
    cout << missingNumber_bit(nums) << endl;
    cout << missingNumber_bs(nums) << endl;
    return 0;
}
