#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// https://hihocoder.com/problemset/problem/1506
//
// Problem:
//      There are N events, the probability of event i occurring is p[i], what is the probability of exactly M events occurring.
//
// Solution:
//      DP, dp[i][j] = the probability of j events occurring in previous i events
//      dp[i][j] = dp[i-1][j-1]*p[i] + dp[i-1][j]*(1-p[i])
//                  event i occurs    event i doesn't occur

const int MAX = 1005;
double p[MAX];
double dp[MAX][MAX];
int N, M;

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> p[i];
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
        dp[i][0] = dp[i-1][0]*(1-p[i]);
        for (int j = 1; j <= M; ++j) {
            dp[i][j] = dp[i-1][j-1]*p[i] + dp[i-1][j]*(1-p[i]);
        }
    }
    printf("%.6f\n", dp[N][M]);
    return 0;
}
