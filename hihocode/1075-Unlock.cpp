#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// http://blog.csdn.net/sr_19930829/article/details/41086501

const int MAX = 305;
int a[MAX], n, k;
double c[MAX][MAX];
double dp[MAX][MAX];
bool visit[MAX];
vector<int> loop;

void getC() {
    c[0][0] = 1.0;
    for (int i = 1; i < MAX; ++i) {
        c[i][0] = 1.0;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
}

double solve() {
    // 置换群循环节
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            int c = 0, j = i;
            while (!visit[j]) {
                ++c; visit[j] = true; j = a[j];
            }
            loop.push_back(c);
        }
    }
    int m = loop.size();
    if (k < m) return 0;

    dp[0][0] = 1.0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            for (int use = 1; use <= loop[i] && j+use <= k; ++use) {
                dp[i+1][j+use] += dp[i][j]*c[loop[i]][use];
            }
        }
    }
    return dp[m][k]/c[n][k];
}

int main() {
    getC();
    int T; cin >> T;
    while (T--) {
        loop.clear();
        memset(visit, 0, sizeof visit);
        memset(dp, 0, sizeof dp);

        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        printf("%.9f\n", solve());
    }
    return 0;
}
