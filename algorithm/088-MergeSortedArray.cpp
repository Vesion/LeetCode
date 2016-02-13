#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0) return;
    nums1.resize(m+n);
    int index = m+n-1;
    int i = m-1, j = n-1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) nums1[index--] = nums1[i--];
        else nums1[index--] = nums2[j--];
    }
    while (j >= 0) nums1[index--] = nums2[j--]; 
    return;
}

int main() {
    vector<int> nums1({});
    vector<int> nums2({2});
    merge(nums1, nums1.size(), nums2, nums2.size());
    for (auto i : nums1)
        cout << i << " ";
    cout << endl;
    return 0;
}
