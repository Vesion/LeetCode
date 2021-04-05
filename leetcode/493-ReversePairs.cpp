#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22

// BST
// TLE, can boost with a self-implemented BST with count
class Solution0 {
public:
    using ll = long long;
    int reversePairs(vector<int>& nums) {
        multiset<ll> m;
        int res = 0;
        for (ll num : nums) {
            auto it = m.upper_bound(2*num);
            res += distance(it, m.end());
            m.insert(num);
        }
        return res;
    }
};

// BIT
class Solution1 {
    vector<int> bit;
    void add(int i, int v) {
        for (; i < bit.size(); i += (i&-i)) bit[i] += v;
    }
    int get(int i) {
        int res = 0;
        for (; i > 0; i -= (i&-i)) res += bit[i];
        return res;
    }
public:
    using ll = long long;
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        bit.resize(n+1, 0);

        vector<ll> sorted(n);
        for (int i = 0; i < n; ++i) sorted[i] = nums[i];
        sort(sorted.begin(), sorted.end());

        int res = 0;
        for (int i = 0; i < n; ++i) {
            int id = upper_bound(sorted.begin(), sorted.end(), 2L*nums[i]) - sorted.begin();
            res += i-get(id);
            int nid = upper_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
            add(nid, 1);
        }
        return res;
    }
};

// merge sort
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        return mergeSort(nums, 0, nums.size());
    }

    int mergeSort(vector<int>& nums, int first, int last) {
        if (first+1 >= last) return 0;
        int mid = first + (last-first)/2;
        int res = mergeSort(nums, first, mid) + mergeSort(nums, mid, last);
        vector<int> cache(last-first, 0);
        int j = mid, k = mid;
        int r = 0;
        for (int i = first; i < mid; ++i) {
            while (j < last && (long long)nums[i] > (long long)nums[j]*2) ++j;
            res += j-mid;
            while (k < last && nums[k] < nums[i]) cache[r++] = nums[k++];
            cache[r++] = nums[i];
        }
        move(cache.begin(), cache.begin()+r, nums.begin()+first);
        return res;
    }
};


int main() {
    return 0;
}
