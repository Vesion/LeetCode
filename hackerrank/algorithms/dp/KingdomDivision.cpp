#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

using ll = long long;
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
vector<int> tree[MAXN];
ll valid[MAXN][2];
ll invalid[MAXN][2];
int N;

void mul(ll& a, ll b) {
    a *= b;
    if (a >= MOD) a %= MOD;
}

void sub(ll& a, ll b) {
    a -= b;
    if (a < 0) a += MOD;
}

void dfs(int u, int par) {
    vector<int> son;
    for (int& v : tree[u]) {
        if (v == par) continue;
        dfs(v, u);
        son.push_back(v);
    }

    invalid[u][0] = invalid[u][1] = 1;
    valid[u][0] = valid[u][1] = 1;
    for (int& v : son) {
        mul(invalid[u][0], valid[v][1]);
        mul(invalid[u][1], valid[v][0]);
    }
    for (int& v : son) {
        mul(valid[u][0], valid[v][0]+valid[v][1]+invalid[v][0]);
        mul(valid[u][1], valid[v][1]+valid[v][0]+invalid[v][1]);
    }
    sub(valid[u][0], invalid[u][0]);
    sub(valid[u][1], invalid[u][1]);
}

int main() {
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1, 1);
    cout << (valid[1][0]+valid[1][1])%MOD << endl;
    return 0;
}
