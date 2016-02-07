#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& result, int n, int k, vector<int> &r, int start) {
    if (r.size() == k) {
        result.push_back(r);
        return;
    }
    for (int i = start; i <= n; ++i) {
        r.push_back(i);
        dfs(result, n, k, r, i+1);
        r.erase(r.end()-1);
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    if (n <= 0 || k <= 0 || n < k) return result;
    vector<int> r;
    dfs(result, n, k, r, 1);
    return result;
}

int main() {
    for (auto i : combine(2, 1)) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
