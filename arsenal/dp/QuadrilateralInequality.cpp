
// https://blog.csdn.net/qq_37656398/article/details/103537173
for (int len = 2; len <= n; ++len) {
    for (int i = 0; i+len-1 <= n; ++i) {
        int j = i+len-1;
        for (int k = p[i][j-1]; k <= p[i+1][j]; ++k) {
            int v = dp[i][k] + dp[k+1][j] + cost[i][j];
            if (v < dp[i][j]) {
                dp[i][j] = v;
                p[i][j] = k;
            }
        }
    }
}