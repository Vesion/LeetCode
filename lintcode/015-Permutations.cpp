#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void dfs(vector<int>& nums, int cur) {
        if (cur == (int)nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = cur; i < (int)nums.size(); ++i) {
            swap(nums[cur], nums[i]);
            dfs(nums, cur+1);
            swap(nums[cur], nums[i]);
        }
    }

    vector<vector<int> > permute(vector<int> nums) {
        if (nums.empty()) return {};
        dfs(nums, 0);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    auto r = s.permute(nums);
    cout << r.size() << endl;
    for (auto i : r) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
