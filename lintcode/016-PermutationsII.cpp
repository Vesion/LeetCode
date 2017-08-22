#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

class Solution {
public:
    set<vector<int>> result; // use set to remove duplicates

    void dfs(vector<int>& nums, int cur) {
        if (cur == (int)nums.size()) {
            result.insert(nums);
            return;
        }
        for (int i = cur; i < (int)nums.size(); ++i) {
            if (i > cur && nums[i] == nums[i-1]) continue; // cannot avoid duplicates, but can improve time
            swap(nums[cur], nums[i]);
            dfs(nums, cur+1);
            swap(nums[cur], nums[i]);
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return vector<vector<int>>(result.begin(), result.end());
    } 
};

int main() {
    Solution s;
    vector<int> nums = {0, 0, 0, 1, 9};
    auto r = s.permuteUnique(nums);
    set<vector<int>> sets(r.begin(), r.end());
    cout << sets.size() << endl;
    
    cout << r.size() << endl;
    for (auto i : r) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
