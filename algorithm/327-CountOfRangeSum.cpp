#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

// Solution 0 : naive brute-force, O(n^2) time, TLE
int countRangeSum_nv(vector<int>& nums, int lower, int upper) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<int> sum(n+1, 0);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i-1] + nums[i-1];
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int s = sum[j] - sum[i] + nums[j-1];
            if (s >= lower && s <= upper) ++result;
        }
    }
    return result;
}


// Solution 1 : merge sort based, O(nlgn) time, O(n) space, 44ms
// Very similar to 315-CountOfSmallerNumbersAfterSelf solution 1:
//      in 315,  count[i] = count of nums[j] - nums[i] < 0 with j > i
//      at here, count[i] = count of a <= sum[j] - sum[i] <= b with j > i, 'sum' is same with solution 0
// what we want is sum(count[:])
// https://leetcode.com/discuss/79083/share-my-solution
int countWithMergeSort(vector<ll>& sum, int first, int last, int lower, int upper) {
    if (first+1 >= last) return 0;
    int mid = first + (last-first)/2;
    int count = countWithMergeSort(sum, first, mid, lower, upper) + countWithMergeSort(sum, mid, last, lower, upper);
    int j = mid, k = mid;
    int t = mid, r = 0; vector<ll> cache(last-first, 0); // merge and sort in cache, copy it to origimal sum finally
    for (int i = first; i < mid; ++i) {
        // count
        while (k < last && sum[k]-sum[i] < lower) ++k;
        while (j < last && sum[j]-sum[i] <= upper) ++j;
        count += j-k;
        // merge and sort
        while (t < last && sum[t] < sum[i]) cache[r++] = sum[t++];
        cache[r++] = sum[i];
    }
    copy(cache.begin(), cache.begin()+r, sum.begin()+first);
    return count;
}

int countRangeSum_ms(vector<int>& nums, int lower, int upper) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<ll> sum(n+1, 0);
    for (int i = 0; i < n; ++i) sum[i+1] = sum[i] + nums[i];
    return countWithMergeSort(sum, 0, n+1, lower, upper);
}


// Solution 2 : BST
//


int main() {
    vector<int> nums = {-2, 5, -1};
    //cout << countRangeSum_nv(nums, -2, 2) << endl;
    cout << countRangeSum_ms(nums, -2, 2) << endl;
    return 0;
}
