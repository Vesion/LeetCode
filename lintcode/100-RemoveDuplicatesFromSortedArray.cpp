#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) return 0;
        int i = 0;
        int first = 0, last = nums.size();
        while (++first != last) {
            if (nums[first] != nums[i])
                nums[++i] = nums[first];
        }
        ++i;
        nums.erase(nums.begin()+i, nums.end());
        return i;
    } 
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 2, 3};
    cout << s.removeDuplicates(nums) << endl;
    for (auto i : nums) cout << i <<" ";
    return 0;
}
