#include <iostream>
#include <vector>
using namespace std;

// Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
// If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the C(n, 2). 

// Solution 0 : brute-force, O(n^2) time, O(1) space
class Solution_0 {
public:
    int countInversions(vector<int>& nums) {
        if (nums.empty()) return 0;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j)
                if (nums[i] > nums[j]) ++count;
        }
        return count;
    }
};


// Solution 1 : merge sort based, O(nlgn) time, O(n) space
class Solution_1 {
public:
    int countInversions(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> c = nums;
        return mergeSort(c, 0, c.size());
    }

    int mergeSort(vector<int>& nums, int first, int last) {
        if (first+1 >= last) return 0;
        int mid = first + (last-first)/2;
        int res = mergeSort(nums, first, mid) + mergeSort(nums, mid, last);
        vector<int> cache(last-first);
        int j = mid, r = 0;
        for (int i = first; i < mid; ++i) {
            while (j < last && nums[j] < nums[i]) cache[r++] = nums[j++];
            cache[r++] = nums[i];
            res += j-mid;
        }
        move(cache.begin(), cache.begin()+r, nums.begin()+first);
        return res;
    }
};


// Solution 2.1 : Binary Indexed Tree
class Solution_21 {
private:
    vector<int> sums;
    void add(int i, int v) {
        i++;
        while (i < (int)sums.size()) {
            sums[i] += v;
            i += (i & -i);
        }
    }
    int query(int i) {
        i++;
        int sum = 0;
        while (i >= 1) {
            sum += sums[i];
            i -= (i & -i);
        }
        return sum;
    }

public:
    int countInversions(vector<int>& nums) {
        vector<int> c = nums;
        sort(c.begin(), c.end());
        int nc = unique(c.begin(), c.end()) - c.begin();
        c.resize(nc);
        sums.resize(nc+1, 0);

        int result = 0;
        for (int i = (int)nums.size()-1; i >= 0; --i) {
            int id = lower_bound(c.begin(), c.end(), nums[i]) - c.begin();
            add(id, 1);
            result += query(id-1);
        }
        return result;
    }
};


// Solution 2.2 : Segment Tree
class Solution_22 {
private:
    vector<int> sums;
    void update(int i, int l, int r, int p, int v) {
        if (l == r) {
            sums[i] += v;
            return;
        }
        int mid = l + (r-l)/2;
        if (p <= mid) update(i*2, l, mid, p, v);
        else update(i*2+1, mid+1, r, p, v);
        sums[i] = sums[i*2] + sums[i*2+1];
    }
    int query(int i, int l, int r, int L, int R) {
        if (R < L) return 0;
        if (L <= l && r <= R) {
            return sums[i];
        }
        int mid = l + (r-l)/2;
        int result = 0;
        if (L <= mid) result += query(i*2, l, mid, L, R);
        if (R > mid) result += query(i*2+1, mid+1, r, L, R);
        return result;
    }

public:
    int countInversions(vector<int>& nums) {
        vector<int> c = nums;
        sort(c.begin(), c.end());
        int nc = unique(c.begin(), c.end()) - c.begin();
        c.resize(nc);
        sums.resize(nc<<4, 0);

        int result = 0;
        for (int i = (int)nums.size()-1; i >= 0; --i) {
            int id = lower_bound(c.begin(), c.end(), nums[i]) - c.begin();
            update(1, 1, nc, id+1, 1);
            result += query(1, 1, nc, 1, id);
        }
        return result;
    }
};



int main() {
    vector<int> nums = {1, 2, 3, 4, 3, 4, 2, 1, 5, 3};
    Solution_0 s0;
    cout << s0.countInversions(nums) << endl;
    Solution_1 s1;
    cout << s1.countInversions(nums) << endl;
    Solution_21 s21;
    cout << s21.countInversions(nums) << endl;
    Solution_22 s22;
    cout << s22.countInversions(nums) << endl;
    return 0;
}
