#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring> 
using namespace std;

// http://acm.hdu.edu.cn/showproblem.php?pid=2089
//
// Given two integers N and M, 0 < N <= M <= 1000000, find how many integers in range[N, M] which has no '4' and '62' in its digits

int digit[32];
int dp[32][10]; // dp[i][j] means the solution for when reach digit i (from high to low), and previous digit is j

int dfs(int pos, int pre, bool limit) {
    if (pos == 0) return 1;
    if (!limit && dp[pos][pre] != -1) return dp[pos][pre];
    int upper = limit ? digit[pos] : 9;
    int res = 0;
    for (int i = 0; i <= upper; ++i) {
        if (pre == 6 && i == 2) continue;
        if (i == 4) continue;
        res += dfs(pos-1, i, limit && i == digit[pos]);
    }
    if (!limit) dp[pos][pre] = res;
    return res;
}

int solve(int n) {
    int i = 1;
    while (n) {
        digit[i++] = n % 10;
        n /= 10;
    }
    return dfs(i-1, -1, true);
}

int main() {
    memset(dp, -1, sizeof dp); // dp has nothing to do with input, so we init it before all things
    int N, M;    
    while ((cin >> N >> M) && N+M) {
        cout << solve(M) - solve(N-1) << endl;
    }
    return 0;
}
