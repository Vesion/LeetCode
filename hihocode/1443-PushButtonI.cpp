#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N;

// combination, choose c unused integers in [1, N]
void combine(int start, int c, int used, string path, vector<pair<string,int>>& r) {
    if (c == 0) {
        r.push_back({path, used});
        return;
    }
    for (int i = start; i <= N; ++i) {
        if (!((used>>i)&1)) combine(i+1, c-1, used|(1<<i), path+to_string(i), r);
    }
}

void solve(int n, int used, string path, vector<string>& res) {
    if (n == 0) {
        path.pop_back();
        res.push_back(path);
        return;
    }
    for (int i = 1; i <= N; ++i) {
        if (i > n) return;
        vector<pair<string,int>> t;
        combine(1, i, used, "", t);
        for (auto& p : t) solve(n-i, p.second, path+p.first+"-", res);
    }
}

int main() {
    cin >> N; 
    vector<string> res;
    solve(N, 0, "", res);
    sort(res.begin(), res.end());
    for (string& r : res) cout << r << endl;
    return 0;
}
