#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solution 1 : sort then interleave, O(nlgn) time, O(n) space
// Sort and write the smaller half of the numbers on the even indexes and the larger half of the numbers on the odd indexes, both from the backend.
class Solution_1 {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        for (int k = 0, i = (n-1)/2, j = n-1; k < n; ++k) {
            nums[k] = k&1 ? sorted[j--] : sorted[i--];
        }
    }
};


// Solution 2 : find median and three-way partition, O(n) time, O(1) space
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
    return 0;
}
