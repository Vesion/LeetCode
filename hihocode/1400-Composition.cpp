#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool g[26][26];
int dp[26];

int main() {
    ios::sync_with_stdio(false);
    int n;    cin >> n;
    string s; cin >> s;
    int m; cin >> m;
    while (m--) {
        char a, b;
        cin >> a >> b;
        g[a-'a'][b-'a'] = true;
        g[b-'a'][a-'a'] = true;
    }

    for (int i = 0; i < n; ++i) {
        int c = s[i]-'a';
        if (!g[c][c]) dp[c]++;
        for (int j = 0; j < 26; ++j) {
            if (!g[c][j] && !g[j][c] && c != j)
                dp[c] = max(dp[c], dp[j]+1);
        }
    }


    int r = 0;
    for (int i : dp) r = max(i, r);
    cout << n-r << endl;
    return 0;
}
