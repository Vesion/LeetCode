#include <iostream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& path, int cur) {
    if (cur == nums.size()) {
        result.push_back(path);
        return;
    }
    dfs(nums, result, path, cur+1);

    path.push_back(nums[cur]);
    dfs(nums, result, path, cur+1);
    path.erase(path.end()-1);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty()) return result;
    sort(nums.begin(), nums.end());
    vector<int> path;
    dfs(nums, result, path, 0);
    return result;
}


// Solution 2 : binary representation
// use set to remove duplicates
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
    vector<int> nums({1, 2, 2});
    for (auto i : subsetsWithDup_it(nums)) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
