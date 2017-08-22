#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 105;
int triangle[MAX][MAX];
int dp[MAX];
int n;

int main() {
    memset(dp, 0, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; ++i) for (int j = 0; j < i; ++j) cin >> triangle[i][j];
    for (int j = 0; j < n; ++j) dp[j] = triangle[n][j];
    for (int i = n-1; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
            dp[j] = max(dp[j], dp[j+1]) + triangle[i][j];
        }
    }
    cout << dp[0] << endl;
    return 0;
}
