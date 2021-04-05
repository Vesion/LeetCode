#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Bottom up DP, need to store the best path
class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {

        vector<vector<int>> adj(n);
        int total_t = targetPath.size();
        for (vector<int> road: roads) {
            int u = road[0];
            int v = road[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<vector<int>> dp(n, vector<int>(targetPath.size(), INT_MAX));
        vector<vector<int>> parent(n, vector<int>(targetPath.size(), INT_MAX));

        for (int u = 0; u < n; u++) {
            string city = targetPath[0];
            dp[u][0] = names[u] == city ? 0 : 1;
        }
        for (int t = 1; t < total_t; t++) {
            for (int u = 0; u < n; u++) {
                string city = targetPath[t];
                int cost =  names[u] == city ? 0 : 1;
                int min_cost = INT_MAX;

                for (int neighbor : adj[u]) {
                    int curr_total_cost = dp[neighbor][t-1] + cost;
                    if (curr_total_cost < min_cost) {
                        parent[u][t] = neighbor;
                        min_cost = curr_total_cost;
                    }
                }
                dp[u][t] = min_cost;
            }
        }
        vector<int> ans(total_t);
        int final_min_cost = INT_MAX;
        int last = -1;
        for (int u = 0; u < n; u++) {
            if (dp[u][total_t-1] < final_min_cost) {
                last = u;
                final_min_cost = dp[u][total_t-1];
            }
        }

        for (int t = total_t - 1; t >=0 ; t--) {
            ans[t] = last;
            last = parent[last][t];
        }
        return ans;

    }
};

int main() {

}
