#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solution 0 : brute-force, O(n^2) time, TLE
int minSubArrayLen_bf(int s, vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int result = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int sum = 0; int j;
        for (j = i; j < n; ++j) {
            sum += nums[j];
            if (sum >= s) {
                result = min(result, j-i+1);
                break;
            }
        }
        if (j == n) break;
        if (result == 1) break;
    }
    return result == INT_MAX ? 0 : result;
}


// Solution 1 : two pointers, O(n) time
int minSubArrayLen_On(int s, vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int result = INT_MAX;
    int left = 0, right = 0, sum = 0;
    for (; right < n; ++right) {
        sum += nums[right];
        while (sum >= s) {
            result = min(result, right-left+1);
            sum -= nums[left++];
        }
    }
    return result == INT_MAX ? 0 : result;
}


// Solution 2 : binary search, O(nlgn) time
// The idea is to first maintain an array of accumulated summations of elements in nums. Then for each element in sums, if it is not less than s, we search for the first element that is greater than sums[i] - s (in fact, this is just what the upper_bound function does) in sums using binary search.
vector<int> accumulate(vector<int>& nums) {
    int n = nums.size();
    vector<int> sums(n + 1, 0);
    for (int i = 1; i <= n; i++) 
        sums[i] = nums[i - 1] + sums[i - 1];
    return sums;
}

int upper_bound(vector<int>& sums, int left, int right, int target) {
    int l = left, r = right;
    while (l < r) {
        int m = l + ((r - l) >> 1);
        if (sums[m] <= target) l = m + 1;
        else r = m;
    }
    return sums[r] > target ? r : -1;
}

int minSubArrayLen_Onlgn(int s, vector<int>& nums) {
    vector<int> sums = accumulate(nums);
    int n = nums.size(), minlen = INT_MAX;
    for (int i = 1; i <= n; i++) { 
        if (sums[i] >= s) {
            int p = upper_bound(sums, 0, i, sums[i] - s);
            if (p != -1) minlen = min(minlen, i - p + 1);
        }
    }
    return minlen == INT_MAX ? 0 : minlen;
}

int main() {
    vector<int> nums = {1, 10, 10, 10};
    cout << minSubArrayLen_bf(25, nums) << endl;
    cout << minSubArrayLen_On(25, nums) << endl;
    cout << minSubArrayLen_Onlgn(25, nums) << endl;
    return 0;
}
