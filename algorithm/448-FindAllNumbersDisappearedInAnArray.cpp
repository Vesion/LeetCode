#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Same with 442-FindAllDuplicatesInAnArray, couting sort
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i+1) res.push_back(i+1);
        }
        return res;
    }
};


int main() {
    Solution s;
    return 0;
}
