#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if (nums.empty()) return {};   
        for (int i = 0; i < (int)nums.size(); ++i) {
            while (nums[i] != i+1) {
                swap(nums[i], nums[nums[i]-1]);
                if (nums[i] == nums[nums[i]-1]) break;
            }
        }

        vector<int> res;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] != i+1) res.push_back(i+1);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    auto r = s.findDisappearedNumbers(nums);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
