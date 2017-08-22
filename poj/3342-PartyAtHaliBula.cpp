#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
#include <map> 
using namespace std;

const int MAXN = 205;
vector<int> tree[MAXN];
int dp[MAXN][2];
map<string, int> id;
int N;
bool uniq;

void dfs(int cur) {
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    for (int i = 0; i < (int)tree[cur].size(); ++i) {
        int child = tree[cur][i];
        dfs(child);
        dp[cur][0] += max(dp[child][0], dp[child][1]);
        dp[cur][1] += dp[child][0];
    }

    // judge unique
    if (uniq && dp[cur][0] > dp[cur][1]) {
        for (int i = 0; i < (int)tree[cur].size(); ++i) {
            int child = tree[cur][i];
            if (dp[child][0] == dp[child][1]) { uniq = false; break; }
        }
    }
}

int main() {
    while (cin >> N && N != 0) {
        id.clear();
        for (int i = 0; i < N; ++i) tree[i].clear();
        memset(dp, 0, sizeof dp);
        int c = 0;
        string emp, boss;
        cin >> boss; id[boss] = c++;
        for (int i = 1; i < N; ++i) {
            cin >> emp >> boss;
            if (!id.count(emp)) id[emp] = c++;
            if (!id.count(boss)) id[boss] = c++;
            tree[id[boss]].push_back(id[emp]);
        }
        uniq = true;
        dfs(0);
        cout << max(dp[0][0], dp[0][1]) << " " << (dp[0][0] != dp[0][1] && uniq ? "Yes" : "No") << endl;
    }
    return 0;
}
