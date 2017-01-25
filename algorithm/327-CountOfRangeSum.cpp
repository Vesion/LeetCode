#include <iostream>
#include <vector>
#include <set> 
using namespace std;


// very similar to 315-CountOfSmallerNumbersAfterSelf
//
// Recall count smaller number after self where we encountered the problem
//      count[i] = count of nums[j] - nums[i] < 0 with j > i
//
// Here, after we did the preprocess, we need to solve the problem
//      count[i] = count of a <= S[j] - S[i] <= b with j > i


// Solution 0 : naive brute-force, O(n^2) time, TLE
class Solution_0 {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sums(n+1, 0);
        for (int i = 1; i <= n; ++i) sums[i] = nums[i-1]+sums[i-1];
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                if (sums[j]-sums[i] >= lower && sums[j]-sums[i] <= upper) ++res;
            }
        }
        return res;
    }
};


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
// For each i, we need to find all j < i, lower <= sums[i]-sums[j] <= upper
//      sums[j] >= sums[i] - upper
//      sums[j] <= sums[i] - lower
class Solution_2 {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> m;
        m.insert(0);
        int res = 0;
        long long sum = 0;
        for (int& num : nums) {
            sum += num;
            auto l = m.lower_bound(sum-upper);
            auto r = m.upper_bound(sum-lower);
            res += distance(l, r);
            m.insert(sum);
        }
        return res;
    }
};


// Solution 3 : BIT
// https://huntzhan.org/leetcode-count-of-range-sum/


// Solution 4 : Segment Tree
// https://discuss.leetcode.com/topic/43615/segment-tree-solution-c-with-brief-explain


int main() {
    Solution s;
    vector<int> nums = {-2, 5, -1};
    cout << s.countRangeSum(nums, -2, 2) << endl;
    return 0;
}
