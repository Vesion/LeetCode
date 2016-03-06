#include <iostream>
#include <vector>
using namespace std;

// Solution 1 : brute-force, O(n) time
int findPeakElement_bf(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i)
        if (nums[i] > nums[i+1]) return i; // here only need to compare nums[i] to nums[i+1]
    return n-1;
}


// Soluton 2 : binary search
int findPeakElement_bs(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    while (left < right) {
        int mid = left + (right-left)/2;
        if (nums[mid] > nums[mid+1])
            right = mid;
        else
            left = mid+1;
    }
    return left;
}

int main() {
    vector<int> nums = {2, 1};
    cout << findPeakElement_bs(nums) << endl;
    return 0;
}
