#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// DFS+memo, O(N*S), N = number of stations, S = maximum miles(fuel) could get
class Solution0 {
public:
    vector<unordered_map<int,int>> dp;
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        dp.resize(n);
        int res = dfs(stations, 0, target, startFuel);
        return res == INT_MAX ? -1 : res;
    }

    int dfs(const vector<vector<int>>& stations, int i, int target, int fuel) {
        if (fuel >= target) return 0;
        if (i == stations.size() || fuel < stations[i][0]) return INT_MAX;
        if (dp[i].count(fuel)) return dp[i][fuel];
        int res = INT_MAX;
        int add = dfs(stations, i+1, target, fuel+stations[i][1]);
        if (add != INT_MAX) res = add+1;
        int noadd = dfs(stations, i+1, target, fuel);
        res = min(res, noadd);
        return dp[i][fuel] = res;
    }
};


// DP, O(N^2)
// dp[i][j] = farthest miles could reach when stop at stations[i] with j refuelings
class Solution1 {
public:
    using ll = long long;
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
        for (int i = 0; i <= n; ++i) dp[i][0] = startFuel;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                // do not refuel at stations[i],
                // which means we want to reach stations[i+1] from a station before i (j < i)
                if (j < i)
                    dp[i+1][j+1] = dp[i][j+1];
                // refuel at stations[i],
                // but it requires we can reach stations[i]
                if (dp[i][j] >= stations[i][0])
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + stations[i][1]);
            }
        }

        int res = INT_MAX;
        for (int j = n; j >= 0; --j) if (dp[n][j] >= target) res = j;
        return res == INT_MAX ? -1 : res;
    }
};

// DP, 1D array
class Solution2 {
public:
    using ll = long long;
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<ll> dp(505, 0);
        dp[0] = startFuel;
        int n = stations.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (dp[j] < stations[i][0]) break;
                dp[j+1] = max(dp[j+1], dp[j] + stations[i][1]);
            }
        }

        for (int i = 0; i <= n; ++i) {
            if (dp[i] >= target) return i;
        }
        return -1;
    }
};


// Greedy, heap
// We don't care at which stations we refueled, we only care the max distance we can reach.
// https://leetcode.com/problems/minimum-number-of-refueling-stops/discuss/294025/Java-Simple-Code-Greedy
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int max_dist = startFuel, i = 0, res = 0;
        priority_queue<int> pq;
        while (max_dist < target) {
            while (i < n && max_dist >= stations[i][0]) {
                pq.push({stations[i++][1]});
            }
            if (pq.empty()) return -1;
            max_dist += pq.top();
            pq.pop();
            ++res;
        }
        return res;
    }
};

int main() {

}
