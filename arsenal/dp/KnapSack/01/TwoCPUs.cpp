#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// Problem:
//      There are two CPUs, they can process task concurrently, given n tasks whose time to process is t[i], what is the minimum time we need to complete processing all tasks
//
// Solution:
//      Accumulate all tasks' time to T, then the problem can be converted to:
//          Given capacity T/2, each item's weight is t[i], value is also t[i], use 01-knapsack to calculate the maximum value we can get, i.e. dp[T/2]
//          then the result of original problem is T-dp[T/2]
//          why? because dp[T/2] must <= T/2, so the other one's time must >= T/2, result is the larger one

const int MAXN = 1000;
const int MAX = 210000;
int t[MAXN];
int dp[MAX];
int n;

int main() {
    cin >> n; 
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        sum += t[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = sum/2; j >= t[i]; --j) {
            dp[j] = max(dp[j], dp[j-t[i]]+t[i]);
        }
    }
    cout << (sum-dp[sum/2]) << endl;
    return 0;
}

