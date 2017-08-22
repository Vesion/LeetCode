#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(vector<int>& nums, int cur) {
        if (cur == (int)nums.size()) {
            result.push_back(path);
            return;
        }

        dfs(nums, cur+1);

        path.push_back(nums[cur]);
        dfs(nums, cur+1);
        path.pop_back();


    }

    vector<vector<int> > subsets(vector<int> &nums) {
        if (nums.empty()) return {};
        dfs(nums, 0);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    auto r = s.subsets(nums);
    cout << r.size() <<endl;
    for (auto i : r) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
