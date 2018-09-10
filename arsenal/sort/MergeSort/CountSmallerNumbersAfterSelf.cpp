#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0), index(n, 0);
        iota(index.begin(), index.end(), 0);
        mergeSort(nums, 0, n, index, res);
        return res;
    }
    
    // sort with indexes
    void mergeSort(vector<int>& nums, int first, int last, vector<int>& index, vector<int>& res) {
        if (first+1 >= last) return;
        int mid = first + (last-first)/2;
        mergeSort(nums, first, mid, index, res); 
        mergeSort(nums, mid, last, index, res);
        vector<int> cache(last-first);
        int j = mid, r = 0;
        int count = 0;
        for (int i = first; i < mid; ++i) {
            while (j < last && nums[index[i]] > nums[index[j]]) {
                ++count;
                cache[r++] = index[j++];
            }
            cache[r++] = index[i];
            res[index[i]] += count;
        }
        move(cache.begin(), cache.begin()+r, index.begin()+first);
    }
};


int main() {
    return 0;
}
