#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX = 100001;
const int MOD = 142857;

int N, M;
int init[MAX];
vector<int> ms[MAX]; // module[i][signals]
vector<int> sm[MAX]; // signal[i][modules]
bool v[MAX];
vector<int> topo;
int dp[MAX];


void dfs(int cur) {
    if (v[cur]) return;
    v[cur] = true;
    for (int s : ms[cur]) {
        for (int m : sm[s]) {
            dfs(m);
        }
    }
    topo.push_back(cur);
}


int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        // init each case
        for (auto &v : sm) v.clear();
        for (auto &v : ms) v.clear();
        topo.clear();
        memset(v, 0, sizeof v);
        memset(dp, 0, sizeof dp);

        int s, k;
        cin >> N >> M;
        for (int i = 0; i < M; ++i) {
            cin >> init[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> s >> k;
            sm[s].push_back(i);
            for (int j = 0; j <  k; ++j) {
                cin >> s;
                ms[i].push_back(s);
            }
        }

        // get inversing topo sort
        for (int i = 0; i < N; ++i) {
            dfs(i);
        }

        // dp
        for (int i = 0; i < M; ++i) {
            for (int m : sm[init[i]])
                dp[m]++;
        }
        for (auto it = topo.rbegin(); it != topo.rend(); it++) {
            int i = *it;
            for (int s : ms[i]) {
                for (int m : sm[s]) {
                    dp[m] += dp[i];
                    if (dp[m] >= MOD) dp[m] -= MOD;
                }
            }
        }

        for (int i = 0; i < N; ++i)
            cout << dp[i] << " ";
        cout << endl;

    }
    return 0;
}
