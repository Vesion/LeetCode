#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// greedy
int solve(vector<pair<int,int>>& s, int x, int y) {
    int n = s.size();
    sort(s.begin(), s.end(), [](const pair<int,int>& i1, const pair<int,int>& i2) {
            if (i1.first == i2.first) return i1.second < i2.second;
            return i1.first < i2.first;
        });

    int res = 0;
    for (int i = 0; i < n; ) {
        if (x >= y) break;
        int nx = x;
        while (i < n && s[i].first <= x) {
            nx = max(nx, s[i].second);
            ++i;
        }
        if (nx == x) return -1;
        x = nx;
        ++res;
    }
    return res;
}

int main() {
    int n;
    int x, y;
    cin >> n >> x >> y;
    vector<pair<int,int>> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i].first >> s[i].second;
    cout << solve(s, x, y) << endl;
    return 0;
}
