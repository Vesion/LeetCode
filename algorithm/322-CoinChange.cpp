#include <iostream>
#include <vector>
using namespace std;

// the famous 'Change Coins' problem, a classical dp problem
// similar to complete knapsack problem


// Solution 0 : dfs (brute-force), TLE
// just for practising dfs. :)
void dfs(vector<int>& coins, int amount, int count, int& result) {
    if (amount < 0) return;
    if (amount == 0) { result = min(count, result); return; }
    for (int i = 0; i < coins.size(); ++i)
        dfs(coins, amount-coins[i], count+1, result);
}

int coinChange_dfs(vector<int>& coins, int amount) {
    int result = INT_MAX;
    dfs(coins, amount, 0, result);
    return result == INT_MAX ? -1 : result;
}


// Solution 1 : dp, O(m*n) time
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < n; ++j) {
            if (coins[j] <= i) // this coin's denomination must not greater than current amount i
                dp[i] = min(dp[i], dp[i-coins[j]]+1); // pick this coin or not
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {2};
    cout << coinChange_dfs(coins, 3) << endl;;
    return 0;
}
