#include <iostream>
#include <vector>
using namespace std;

// This problem's original model is 'Dutch National Flag Problem' (https://en.wikipedia.org/wiki/Dutch_national_flag_problem)
// Simply speaking, we need to rearrange the array into three part with a given number x:
//      first part is numbers smaller than x, middle part is numbers euqal to x, last part is numbers greater than x.
//      numbers of any one part can be arbitrary order
// e.g.
//      [8, 4, 2, 5, 0, 1, 9, 5, 4], given x is 5, one possible result is:
//      [0, 2, 4, 1, 4, 5, 5, 9, 8]
//
void threeWayPartition(vector<int>& nums, int x) {
    if (nums.empty()) return;
    int i = 0, j = nums.size()-1, k = 0;
    while (k <= j) { // three way
        if (nums[k] < x)
            swap(nums[k++], nums[i++]);
        else if (nums[k] > x)
            swap(nums[k], nums[j--]);
        else
            ++k;
    }
}


// A hard case wich uses three-way partition
// https://leetcode.com/problems/wiggle-sort-ii
//
// Solution : find median and three-way partition, O(n) time, O(1) space
// Do we really need to sort the whole array? Of course not, we just need three-parts sorted, it's three-way-partition.
//      find median has been solved in 215-KthLargestElementInAnArray
//      three-way partition has been solved in 075-SortColors
// So, we just need to 1. find median, 2. use three way partition, 3. reorder the array with odd and even interleaving like solution 1.
// But, for better performance and neater codes, we combine step 2 and 3.
// what's really tricky is how to map original indicies to its destined indices, see https://leetcode.com/discuss/77133/o-n-o-1-after-median-virtual-indexing
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // Find a median.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        // Index-rewiring.
        #define v(i) (2*i+1) % (n|1)

        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        // put larger half on the odd positions, smaller half on the even positions
        int i = 0, j = 0, k = n - 1;
        while (i <= k) {
            if (nums[v(i)] > mid)
                swap(nums[v(i++)], nums[v(j++)]);
            else if (nums[v(i)] < mid)
                swap(nums[v(i)], nums[v(k--)]);
            else
                i++;
        }
    }
};


int main() {
    vector<int> nums = {9, 1, 4, 5, 4, 2, 8, 5};
    threeWayPartition(nums, 4);
    for (auto i : nums) cout << i << " "; cout << endl;
    return 0;
}
