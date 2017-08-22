#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// https://hihocoder.com/discuss/question/4346

using ll = long long;
const int MAX = 1005;
const int MOD = 1000000007;
ll dp[MAX][MAX];

pair<int, ll> solve(string& s) {
    int p = 0, q = 0, maxd = 0;
    vector<int> least;
    for (char& c : s) {
        if (c == '(') ++q;
        else {
            ++p;
            maxd = max(maxd, p-q);
            least.push_back(p-q);
        }
    }
    while (!least.empty() && least.back() < maxd) least.pop_back();
    if (least.empty()) return {0, 1};

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    int n = least.size();
    for (int i = 1; i <= n; ++i) {
        for (int j = max(0, least[i-1]); j <= maxd; ++j) {
            for (int k = 0; k <= j; ++k) dp[i][j] += dp[i-1][k];
            dp[i][j] %= MOD;
        }
    }
    return {maxd, dp[n][maxd]};
}

int main() {
    string s; cin >> s; 
    auto l = solve(s);
    reverse(s.begin(), s.end());
    for (char& c : s) c = c == '(' ? ')' : '(';
    auto r = solve(s);
    cout << l.first+r.first << " " << l.second*r.second%MOD << endl;
    return 0;
}
