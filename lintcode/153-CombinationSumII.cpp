#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(vector<int>& num, int cur, int sum, int target) {
        if (sum > target) return;
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = cur; i < (int)num.size(); ++i) {
            if (i > cur && num[i] == num[i-1]) continue; // in case of duplicates
            path.push_back(num[i]); 
            dfs(num, i+1, sum+num[i], target);
            path.pop_back();
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        if (num.empty()) return {};
        sort(num.begin(), num.end());
        dfs(num, 0, 0, target);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> c = {8, 7, 4, 3};
    auto r = s.combinationSum2(c, 11);
    for (auto i : r) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}
