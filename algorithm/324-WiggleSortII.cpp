#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solution 1 : sort then interleave, O(nlgn) time, O(n) space
// Sort and then write the smaller half of the numbers on the even indexes and the larger half of the numbers on the odd indexes, both from the back. 
// e.g.
//      Small half:    4 . 3 . 2 . 1 . 0 .
//      Large half:    . 9 . 8 . 7 . 6 . 5
//      ----------------------------------
//      Together:      4 9 3 8 2 7 1 6 0 5
// here is its correctness proof : // https://leetcode.com/discuss/76965/3-lines-python-with-explanation-proof
void wiggleSort_sort(vector<int>& nums) {
    if (nums.empty()) return;
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    int n = nums.size();
    for (int k = 0, i = (n+1)/2-1, j = n-1; k < n; ++k)
        nums[k] = k&1 ? sorted[j--] : sorted[i--];
}


// Solution 1 : find median and three-way partition, O(n) time, O(1) space ?
// Do we really need to sort the whole array? Of course not, we just need three-parts sorted, it's three-way-partition.
//      find median has been solved in 215-KthLargestElementInAnArray
//      three-way partition has been solved in 075-SortColors
// So, we just need to 1. find median, 2. use three way partition, 3. reorder the array with odd and even interleaving like solution 1.
// But, for better performance and neater codes, we combine step 2 and 3.
// what's really tricky is how to map original indicies to its destined indices, see https://leetcode.com/discuss/77133/o-n-o-1-after-median-virtual-indexing
void wiggleSort(vector<int>& nums) {
    if (nums.empty()) return;
    int n = nums.size();

    // find median use std::nth_element, its average time is O(n)
    auto midit = nums.begin() + n/2;
    nth_element(nums.begin(), midit, nums.end());
    int median = *midit;

    // a lambda to remap indices
    auto index = [=](int i) { return (2 * i + 1) % (n | 1); };

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    int i = 0, j = n-1, k = 0;
    while (k <= j) {
        if (nums[index(k)] > median)
            swap(nums[index(i++)], nums[index(k++)]);
        else if (nums[index(k)] < median)
            swap(nums[index(k)], nums[index(j--)]);
        else
            ++k;
    }
}

int main() {
    vector<int> nums = {4, 5, 5, 6};
    wiggleSort(nums);
    for (auto i : nums) cout << i << " "; cout << endl;
    return 0;
}
