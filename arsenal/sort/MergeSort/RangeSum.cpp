#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

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


int main() {
    return 0;
}
