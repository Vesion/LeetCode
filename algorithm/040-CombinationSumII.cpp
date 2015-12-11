#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, int rest, vector<int>& candidates, vector<int>& r, vector<vector<int>>& result) {
    if (rest == 0) {
        result.push_back(r);
        return;
    }
    int prev = -1;
    for (int i = start; i < candidates.size(); ++i) {
        if (candidates[i] > rest) // prune
            return;
        if (candidates[i] == prev) // if this number has been chosen, skip
            continue;
        prev = candidates[i]; // store this number
        r.push_back(candidates[i]);
        dfs(i+1, rest-candidates[i], candidates, r, result);
        r.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    if (candidates.size() == 0)
        return result;
    sort(candidates.begin(), candidates.end());
    vector<int> r;
    dfs(0, target, candidates, r, result);
    return result;
}

int main() {
    vector<int> a{10,1,2,7,6,1,5};
    for (auto i : combinationSum2(a, 8)) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
