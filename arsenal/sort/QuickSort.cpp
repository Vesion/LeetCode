#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left]; // here we use nums[left] as the `pivot`, but the ideal pivot is the `median of three`
    int l = left+1, r = right-1;
    while (l <= r) {
        while (l <= r && nums[l] <= pivot) ++l;
        while (l <= r && nums[r] >= pivot) --r;
        if (l <= r) swap(nums[l++], nums[r--]);
    }
    swap(nums[left], nums[r]);
    return r;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left < right) { // [left, right) is divided into [left, p), p, [p+1, right)
        int p = partition(nums, left, right);
        quickSort(nums, left, p);
        quickSort(nums, p+1, right);

    }
}

int main() {
    vector<int> nums = {1, 5, 8, 0, -1, 11, 7, 6, 5, 4, 5, 4, 1, 3, 2};
    quickSort(nums, 0, nums.size());
    for (auto i:nums) cout << i << " "; cout << endl;
    return 0;
}
