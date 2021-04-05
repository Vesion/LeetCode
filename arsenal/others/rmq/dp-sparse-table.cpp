#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;


const int MAXN = 100;

int nums[MAXN];
int dp[MAXN][MAXN]; // dp[i][j] = the minimum value of nums[i, i+(1<<j)), length of pow(2, j)
int N, Q;

void preprocess() {
    for (int i = 0; i < N; ++i) dp[i][0] = nums[i];
    for (int j = 1; (1<<j) <= N; ++j) {
        for (int i = 0; (i+(1<<j)-1) < N; ++i) {
            dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l, int r) {
    int p = (int)log2(r-l+1);
    return min(dp[l][p], dp[r-(1<<p)+1][p]);
}


int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; ++i) cin >> nums[i];
    preprocess();
    for (int i = 0; i < Q; ++i) {
        int l, r; cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}
