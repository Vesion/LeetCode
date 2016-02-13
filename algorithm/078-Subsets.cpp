#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// a classical dfs-backtracking problem


// a standard backtracking solution
void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& r, int start) {
    if (start == nums.size()) {
        result.push_back(r);
        return;
    }

    // do not pick nums[start]
    dfs(nums, result, r, start+1);

    // pick nums[start]
    r.push_back(nums[start]);
    dfs(nums, result, r, start+1);
    r.erase(r.end()-1);
}

vector<vector<int>> subsets_dfs(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty())
        return result;
    vector<int> r;
    sort(nums.begin(), nums.end());
    dfs(nums, result, r, 0);
    return result;
}


// an iteration solution
// use binary presentation to count, e.g. 0000~1111
vector<vector<int>> subsets_it(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.empty())
        return result; 
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> r;
        for (int j = 0; j < n; ++j)
            if ((i >> j) & 1)
                r.push_back(nums[j]); 
        result.push_back(r);
    }
    return result;
}


int main() {
    vector<int> nums = {1, 2, 3};
    //auto result = subsets_dfs(nums);
    auto result = subsets_it(nums);
    cout << endl << "main" << endl;
    for (auto i : result) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
