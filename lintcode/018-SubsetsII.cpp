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
        result.push_back(path);
        if (cur >= (int)nums.size()) return;
        for (int i = cur; i < (int)nums.size(); ++i) {
            if (i > cur && nums[i] == nums[i-1]) continue; // in case of duplicates
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        if (S.empty()) return {};
        sort(S.begin(), S.end());
        dfs(S, 0);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 2};
    auto r = s.subsetsWithDup(nums);
    cout << r.size() << endl;
    for (auto i : r) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
