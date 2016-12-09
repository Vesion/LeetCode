#include <iostream>
#include <vector>
#include <set> 
using namespace std;


// Solution 0 : naive brute-force, O(n^2) time, TLE


// Solution 1 : merge sort based, O(nlgn) time, O(n) space, 44ms
// Very similar to 315-CountOfSmallerNumbersAfterSelf solution 1:
//      in 315,  count[i] = count of nums[j] - nums[i] < 0 with j > i
//      at here, count[i] = count of a <= sum[j] - sum[i] <= b with j > i, 'sum' is same with solution 0
// what we want is sum(count[:])
// https://discuss.leetcode.com/topic/33738/share-my-solution
class Solution {
public:
    typedef long long ll;

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<ll> sum(n+1, 0);
        for (int i = 0; i < n; ++i) sum[i+1] = sum[i] + nums[i];
        return mergeCount(sum, 0, n+1, lower, upper);
    }

    int mergeCount(vector<ll>& sum, int first, int last, int lower, int upper) {
        if (first+1 >= last) return 0;
        int mid = first + (last-first)/2;
        int count = mergeCount(sum, first, mid, lower, upper) + mergeCount(sum, mid, last, lower, upper);
        int j = mid, k = mid;
        int t = mid, r = 0; 
        vector<ll> cache(last-first, 0); // merge and sort in cache, copy it to origimal sum finally
        for (int i = first; i < mid; ++i) {
            // count
            while (k < last && sum[k]-sum[i] < lower) ++k;
            while (j < last && sum[j]-sum[i] <= upper) ++j;
            count += j-k;
            // merge and sort
            while (t < last && sum[t] < sum[i]) cache[r++] = sum[t++];
            cache[r++] = sum[i];
        }
        move(cache.begin(), cache.begin()+r, sum.begin()+first);
        return count;
    }
};


// Solution 2 : BST, multiset
// For each i, we need to find all j > i, lower <= sums[j]-sums[i] <= upper
class Solution_2 {
public:
    using ll = long long;

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return 0;
        int n = nums.size();

        vector<ll> sums(n+1, 0);
        for (int i = 0; i < n; ++i) sums[i+1] = sums[i] + nums[i];

        int res = 0;
        multiset<ll> ms;
        for (int i = n; i >= 1; --i) {
            ms.insert(sums[i]);
            auto lo = ms.lower_bound(lower + sums[i-1]);
            auto up = ms.upper_bound(upper + sums[i-1]);
            res += distance(lo, up);
        }
        return res;
    }
};


// Solution 3 : BIT
// https://huntzhan.org/leetcode-count-of-range-sum/


// Solution 4 : Segment Tree
// https://discuss.leetcode.com/topic/43615/segment-tree-solution-c-with-brief-explain


int main() {
    return 0;
}
