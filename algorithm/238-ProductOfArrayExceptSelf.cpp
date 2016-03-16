#include <iostream>
#include <vector>
using namespace std;

// Solution 1 : use left and right product array, three passes, O(3*n) time, O(2*n) space
vector<int> productExceptSelf_On(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n+1, 1), right(n+1, 1);
    for (int i = 0; i < n; ++i) left[i+1] = left[i] * nums[i];
    for (int i = n-1; i >= 0; --i) right[i] = right[i+1] * nums[i];
    vector<int> result(n);
    for (int i = 0; i < n; ++i) result[i] = left[i] * right[i+1];
    return result;
}


// Solution 2 : nums as left, result as right, three passes, O(3*n) time, O(1) space
vector<int> productExceptSelf_O1(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n+1, 1);
    for (int i = 0; i < n; ++i) result[i+1] = result[i] * nums[i];
    nums.push_back(1);
    for (int i = n-1; i >= 0; --i) nums[i] = nums[i+1] * nums[i];
    for (int i = n; i > 0; --i) result[i] = result[i-1] * nums[i];
    result.erase(result.begin());
    return result;
}


// Soluton 3 : one pass, O(n) time, O(1) space
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    int left = 1, right = 1;
    vector<int> result(n, 1);
    for (int i = 0; i < n; ++i) {
        result[i] *= left;
        left *= nums[i];
        result[n-1-i] *= right;
        right *= nums[n-1-i];
    }
    return result;
}


int main() {
    vector<int> nums = {1, 2, 3, 4};
    auto r = productExceptSelf(nums);
    for (auto i:r) cout << i << " "; cout << endl;
    return 0;
}
