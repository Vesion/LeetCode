#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(vector<int>& c, int t, int cur, int sum) {
        if (sum > t) return;
        if (sum == t) {
            result.push_back(path);
            return;
        }
        for (int i = cur; i < (int)c.size(); ++i) {
            path.push_back(c[i]);
            dfs(c, t, i, sum+c[i]);
            path.pop_back();
        }
    }


    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0);
        return result;
    } 
};

int main() {
    Solution s;
    vector<int> c = {8, 7, 4, 3};
    auto r = s.combinationSum(c, 11);
    for (auto i : r) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}
