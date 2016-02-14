#include <iostream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

// Solution 1 : dfs backtracking
// 思路与078-Subsets.cpp类似，在078中每个元素都不同，所以每个元素只有选0和1次两种，
// 而现在有重复元素，所以每个元素都可以选0到若干次
void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& path, int cur) {
    result.push_back(path);

    for (int i = cur; i < nums.size(); ++i) {
        if (i != cur && nums[i] == nums[i-1]) // process only one element in duplicates
            continue;
        path.push_back(nums[i]);
        dfs(nums, result, path, i+1);
        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup_dfs(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty()) return result;
    sort(nums.begin(), nums.end());
    vector<int> path;
    dfs(nums, result, path, 0);
    return result;
}


// Solution 2 : binary representation
// use 'set' to remove duplicates
vector<vector<int>> subsetsWithDup_it(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty())
        return result; 
    sort(nums.begin(), nums.end());
    set<vector<int>> s_result;
    int n = nums.size();
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> r;
        for (int j = 0; j < n; ++j)
            if ((i >> j) & 1)
                r.push_back(nums[j]); 
        s_result.insert(r);
    }
    copy(s_result.begin(), s_result.end(), back_inserter(result));
    return result;
}


int main() {
    vector<int> nums({1, 2, 3, 4});
    auto result = subsetsWithDup_dfs(nums);
    //auto result = subsetsWithDup_it(nums);
    for (auto i : result) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
