#include <iostream>
#include <vector>
using namespace std;

// a classical greedy problem

// Before solving the real problem directly, let's do two simpler problems. Then we can find they are sub routine of real problem.


// Step 1 : consider a simple problem, create a maximum number of k length from only one array
// the greedy strategy is maintain a k-length maximum stack
vector<int> maxArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> result(k);
    for (int i = 0, j = 0; i < n; ++i) {
        // 1. n-i-j > k, ensure the rest numbers can at least form a k-length result
        // 2. j > 0, ensure the stack is not empty
        // 3. result[j-1] < nums[i], ensure the greedy strategy, pop smaller numbers than the new number
        while (n-i+j > k && j > 0 && result[j-1] < nums[i]) --j;
        if (j < k) result[j++] = nums[i];
    }
    return result;
}

// Step 2 : consider another problem, given two arrays of length m and n, create a maximum number of k = m+n
// This procedure is like merge in merge sort, choose the larger one from two array.
// But how to choose when they are equal? We need to see what behind the two to decide.
bool larger(vector<int>& nums1, int m, int i, vector<int>& nums2, int n, int j) {
    while (i < m && j < n && nums1[i] == nums2[j]) ++i, ++j;
    return j == n || (i < m && nums1[i] > nums2[j]);
}
vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
    int k = nums1.size() + nums2.size();
    vector<int> result(k);
    for (int i = 0, j = 0, r = 0; r < k; ++r)
        result[r] = larger(nums1, nums1.size(), i, nums2, nums2.size(), j) ? nums1[i++] : nums2[j++];
    return result;
}

// Step 3 : come back to real problem, what the rest work is how can we use two steps above?
// The answer is divide the result into two parts, i and k-i length. 
// First find the max number of length i in one array, find the max number of length k-i in another array, with 'maxArray'
// Then merge the two parts into one of length k, with 'merge'.
// How to decide i? Greedy. Iterate and maintain the maximum number.
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    vector<int> result(k);
    for (int i = max(0, k-n); i <= min(k, m); ++i) {
        auto first = maxArray(nums1, i), second = maxArray(nums2, k-i);
        auto candidate = merge(first, second);
        if (larger(candidate, k, 0, result, k, 0)) result = candidate;
    }
    return result;
}

int main() {
    vector<int> nums1 = {3, 4, 6, 5};
    vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    auto r = maxNumber(nums1, nums2, 5);
    for (auto i:r) cout << i; cout << endl;
    return 0;
}
