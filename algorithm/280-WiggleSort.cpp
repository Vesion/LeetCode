#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// The final sorted nums needs to satisfy two conditions:
//      1. If i is odd, then nums[i] >= nums[i - 1];
//      2. If i is even, then nums[i] <= nums[i - 1].
// The code is just to fix the orderings of nums that do not satisfy 1 and 2.
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size()-1; ++i) {
            if (i%2 == 1 && nums[i] < nums[i+1]) swap(nums[i], nums[i+1]);
            if (i%2 == 0 && nums[i] > nums[i+1]) swap(nums[i], nums[i+1]);
        }
    }
};


int main() {
    Solution s;
    vector<int> n = {6,5,4,3,2,1};
    s.wiggleSort(n);
    for (auto& e : n) cout << e << " "; cout << endl; 
    return 0;
}

