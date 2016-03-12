#include <iostream>
#include <vector>
using namespace std;

// Solution 1 : trivial dfs
void dfs(vector<vector<int>>& result, vector<int>& path, int k, int n, int sum, int start) {
    if (sum == n) {
        if (path.size() == k) result.push_back(path);
        return;
    }
    for (int i = start; i <= 9; ++i) {
        if (sum+i > n) return;
        path.push_back(i);
        dfs(result, path, k, n, sum+i, i+1);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(result, path, k, n, 0, 1);
    return result;
}

int main() {
    auto r = combinationSum3(3, 100);
    for (auto i : r) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}
