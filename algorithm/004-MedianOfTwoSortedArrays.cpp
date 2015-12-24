#include <iostream>
#include <vector>
using namespace std;

/*
 * This question is a special case of 'find-kth element in two sorted array'
 * median indicates that k is (m+n)/2
 */

int findKth(int nums1[], int ln1, int nums2[], int ln2, int k) {
    if (ln1 > ln2) // ensure nums1 is shorter than nums2
        return findKth(nums2, ln2, nums1, ln1, k);
    if (ln1 == 0)
        return nums2[k-1];
    if (k == 1)
        return min(nums1[0], nums2[0]);

    int k1 = min(ln1, k / 2);
    int k2 = k - k1;
    if (nums1[k1-1] < nums2[k2-1]) {
        return findKth(nums1 + k1, ln1 - k1, nums2, ln2, k - k1);
    }
    else if (nums1[k1-1] > nums2[k2-1]) {
        return findKth(nums1, ln1, nums2 + k2, ln2 - k2, k - k2);
    }
    //else if (nums1[k1-1] == nums2[k2-1])
    return nums1[k1-1]; // or nums2[k2-1]
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int ln1 = nums1.size(), ln2 = nums2.size();
    if ((ln1 + ln2) & 0x1) { // odd
        return findKth(&nums1[0], ln1, &nums2[0], ln2, (ln1 + ln2) / 2 + 1);
    }
    else { // even
        return (findKth(&nums1[0], ln1, &nums2[0], ln2, (ln1 + ln2) / 2) + 
                findKth(&nums1[0], ln1, &nums2[0], ln2, (ln1 + ln2) / 2 + 1)) * 0.5;
    }
}

int main() {
    vector<int> a({1});
    vector<int> b({1});
    cout << findMedianSortedArrays(a, b) << endl;
    return 0;
}
