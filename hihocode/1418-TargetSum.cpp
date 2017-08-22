#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
using namespace std;

using ll = long long;
const ll MOD = 1000000007;

ll solve(vector<ll>& nums, ll S) {
    ll sum = accumulate(nums.begin(), nums.end(), 0);
    if (S < -sum || S > sum || (S+sum)&1) return 0; // invalid S
    S = (S + sum) / 2;

    vector<ll> dp(S+1, 0);
    dp[0] = 1;
    for (ll& num : nums) {
        for (ll i = S; i >= num; --i) {
            dp[i] = (dp[i] + dp[i-num]) % MOD;
        }
    }
    return dp[S];
}

int main() {
    int N, S; 
    cin >> N >> S;
    vector<ll> nums(N);
    for (int i = 0; i < N; ++i) cin >> nums[i];
    cout << solve(nums, S);
    return 0;
}
