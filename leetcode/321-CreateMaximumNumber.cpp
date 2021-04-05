#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// O((m+n)^3)
// It is possible to achieve O(n + m) runtime for the merge function by by creating a suffix array on the concatenation of nums1 and nums2.
// Therefore, the total runtime can be further improved to O((n+m)^2).
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res(k);
        for (int i = max(0, k-n); i <= min(k, m); ++i) {
            auto first = getMax(nums1, i);
            auto second = getMax(nums2, k-i);
            auto candidate = merge(first, second);
            if (larger(candidate, k, 0, res, k, 0)) res = candidate;
        }
        return res;
    }

    // get the max k-digits-number in a array, stack, O(n)
    vector<int> getMax(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(k);
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j > 0 && nums[i] > res[j-1] && j+n-i > k) --j;
            if (j < k) res[j++] = nums[i];
        }
        return res;
    }

    // merge two numbers into a largest number, O((m+n)^2)
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res(m+n);
        for (int i = 0, j = 0, k = 0; k < m+n; ++k)
            res[k] = larger(nums1, m, i, nums2, n, j) ? nums1[i++] : nums2[j++];
        return res;
    }

    // compare two numbers, O(m+n)
    bool larger(vector<int>& nums1, int m, int i, vector<int>& nums2, int n, int j) {
        while (i < m && j < n && nums1[i] == nums2[j]) ++i, ++j;
        return j == n || (i < m && nums1[i] > nums2[j]);
    }
};


int main() {
    Solution s;
    vector<int> nums1 = {3,4,6,5};
    vector<int> nums2 = {9,1,2,5,8,3};
    auto r = s.maxNumber(nums1, nums2, 5);
    for (auto& e : r) cout << e << " "; cout << endl;
    return 0;
}
