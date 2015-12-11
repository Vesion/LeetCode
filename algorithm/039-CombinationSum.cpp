#include <iostream>
#include <vector>
using namespace std;

//
// classical backtracking problem
// dfs + prune 
//

void dfs(int start, int rest, vector<int>& candidates, vector<int>&r, vector<vector<int>>& results) {
    if (rest == 0) { // one solution found
        results.push_back(r);
        return;
    }
    for (int i = start; i < candidates.size(); ++i) {
        if (candidates[i] > rest) // prune
            return;
        r.push_back(candidates[i]);
        dfs(i, rest - candidates[i], candidates, r, results);
        r.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> results;
    if (candidates.empty())
        return results;
    vector<int> r;
    sort(candidates.begin(), candidates.end());
    dfs(0, target, candidates, r, results);
    return results;
}

int main() {
    vector<int> c{1, 2, 3, 6, 7};
    for (auto i : combinationSum(c, 7)) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
