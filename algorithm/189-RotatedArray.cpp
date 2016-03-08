#include <iostream>
#include <vector>
using namespace std;

// Solution 1 : store right k numbers, use O(k) space
void rotate_Ok(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    vector<int> right(k);
    for (int i = n-k, j = 0; i < n; ++i, ++j)
        right[j] = nums[i];
    for (int i = n-1; i >= k; --i)
        nums[i] = nums[i-k];
    for (int i = 0; i < k; ++i)
        nums[i] = right[i];
}


// Solution 2 : reverse all, reverse first k, reverse last n-k, O(1) space
void rotate_reverse(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
}


// Solution 3 : swap the last k with first k, O(1) space
void rotate_swap(vector<int>& nums, int k) 
{
    int *a = &nums[0];
    int n = nums.size();
    for (; k%=n; n -= k, a += k)
    {
        // Swap the last k elements with the first k elements. 
        // The last k elements will be in the correct positions
        // but we need to rotate the remaining (n - k) elements 
        // to the right by k steps.
        for (int i = 0; i < k; i++)
            swap(a[i], a[n - k + i]);
    }
}


int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    rotate_swap(nums, 2);
    for (auto i : nums) cout << i << " "; cout << endl;
    return 0;
}
