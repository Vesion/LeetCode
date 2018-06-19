#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Same with Inversion Count problem
// can be solved with merge sort, binary indexed tree and segment tree

// Solution 1.0 : merge sort, O(nlogn)
class Solution_1_0 {
public:
  bool isIdealPermutation(vector<int>& nums) {
    int local = 0;
    for (int i = 1; i < (int)nums.size(); ++i) local += nums[i-1] > nums[i];
    return local == mergeSort(nums, 0, nums.size());
  }

  int mergeSort(vector<int>& nums, int start, int end) {
    if (start+1 >= end) return 0;
    int mid = start + (end-start)/2;
    int res = mergeSort(nums, start, mid) + mergeSort(nums, mid, end);
    vector<int> cache(end-start);
    int j = mid, r = 0;
    for (int i = start; i < mid; ++i) {
      while (j < end && nums[j] < nums[i]) cache[r++] = nums[j++];
      cache[r++] = nums[i];
      res += j-mid;
    }
    move(cache.begin(), cache.begin()+r, nums.begin()+start);
    return res;
  }
};

// Solution 1.1 : binary indexed tree, O(nlogn)
class Solution_1_1 {
private:
  vector<int> sums;
  void add(int i, int v) {
    ++i;
    while (i < (int)sums.size()) {
      sums[i] += v;
      i += (i & -i);
    }
  }
  int query(int i) {
    ++i;
    int sum = 0;
    while (i >= 1) {
      sum += sums[i];
      i -= (i & -i);
    }
    return sum;
  }

public:
  bool isIdealPermutation(vector<int>& nums) {
    int n = nums.size();
    int local = 0;
    for (int i = 1; i < n; ++i) local += nums[i-1] > nums[i];
    
    sums.resize(n+1, 0);
    int global = 0;
    for (int i = n-1; i >= 0; --i) {
      add(nums[i], 1);
      global += query(nums[i]-1);
    }
    return local == global;
  }
};


// Solution 2 : local is global but global may not be local, O(n)
// Note that the given nums is an unordered permutation
// https://leetcode.com/problems/global-and-local-inversions/discuss/113656/My-3-lines-C++-Solution
class Solution {
public:
  bool isIdealPermutation(vector<int>& nums) {
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (abs(nums[i]-i) > 1) return false;
    }
    return true;
  }
};


int main() {
  Solution_1_1 s;
  vector<int> a = {1,2,0};
  cout << s.isIdealPermutation(a) << endl;
  return 0;
}
