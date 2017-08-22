#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

using ll = long long;
const int MAX = 100005;
const int MOD = 1000000007;

// trivial dp, O(n^2), TLE
ll solve_n2() {
    int sums[MAX];
    int dp[MAX];
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) {
        int num; cin >> num;
        sums[i] = sums[i-1] + num;
    }
    dp[0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (sums[i]-sums[j] != 0) dp[i] += dp[j];
        }
    }
    return dp[N];
}


ll solve_n() {
    int N;
    cin >> N;
    unordered_map<int, ll> m;
    m[0] = 1;
    ll res = 0, total = 1;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int num; cin >> num;
        sum += num;
        res = (total - m[sum] + MOD) % MOD;
        m[sum] = (m[sum] + res) % MOD;
        total = (total + res) % MOD;
    }
    return res;
}



int main() {
    cout << solve_n() << endl;
    return 0;
}
