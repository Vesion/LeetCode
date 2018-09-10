#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> lnums(nums.begin()+left, nums.begin()+mid);
    vector<int> rnums(nums.begin()+mid, nums.begin()+right);
    int ln = mid-left, rn = right-mid;
    int i = 0, j = 0, k = left;
    while (i < ln && j < rn) {
        if (lnums[i] < rnums[j]) nums[k++] = lnums[i++];
        else nums[k++] = rnums[j++];
    }
    while (i < ln) nums[k++] = lnums[i++];
    while (j < rn) nums[k++] = rnums[j++];
}

void mergeSort(vector<int>& nums, int left, int right) {
    if (left < right-1) { // [left, right) is divided into [left, mid) and [mid, right)
        int mid = left + (right-left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid, right);
        merge(nums, left, mid, right);
    }
}

int main() {
    vector<int> nums = {2, 1};
    mergeSort(nums, 0, nums.size());
    for (auto i : nums) cout << i << " "; cout << endl;
    return 0;
}
