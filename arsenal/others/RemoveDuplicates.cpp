#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Given a sorted array, remove the duplicates in place and return the new length.


// Version 1 : Each element is allowed to appear only `once`
//
// use std::unique
int removeDumplicates_1_stl(vector<int>& nums) {
    auto it = unique(nums.begin(), nums.end());
    nums.erase(it, nums.end());
    return it-nums.begin();
}

int removeDumplicates_1(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n;
    int r = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] != nums[r-1])
            nums[r++] = nums[i];
    }
    if (r < n) nums.erase(nums.begin()+r, nums.end());
    return r;
}


// Version 2 : Generally, each element is allowed to appear `k` times 
//
int removeDumplicates_k(vector<int>& nums, int k) {
    int n = nums.size();
    if (n <= k) return n;
    int r = k;
    for (int i = k; i < n; ++i) {
        if (nums[i] != nums[r-k])
            nums[r++] = nums[i];
    }
    if (r < n) nums.erase(nums.begin()+r, nums.end());
    return r;
}


int main() {
    vector<int> n1 = {1, 1, 1, 1, 2, 2, 3, 5};    
    cout << removeDumplicates_1(n1) << endl;
    for (auto i : n1) cout << i << " "; cout << endl;


    vector<int> n2 = {1, 1, 1, 1, 2, 2, 3, 5};    
    cout << removeDumplicates_k(n2, 2) << endl;
    for (auto i : n2) cout << i << " "; cout << endl;
    return 0;
}
