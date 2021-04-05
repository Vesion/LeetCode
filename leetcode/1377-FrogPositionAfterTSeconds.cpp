#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// BFS
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> g(n+1);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        queue<pair<int,double>> q;
        q.push({1, 1.0}); ++t;
        int res = 1.0;
        while (!q.empty() && t--) {
            int len = q.size();
            while (len--) {
                int i = q.front().first;
                double p = q.front().second;
                int num_child = i == 1 ? g[i].size() : g[i].size()-1;
                if (i == target) {
                    if (t > 0 && num_child > 0) return 0;
                    return p;
                }
                q.pop();
                for (int j : g[i]) {
                    if (j == i) continue;
                    q.push({j, p / num_child});
                }
            }
        }
        return 0;
    }
};

// DFS
class Solution1 {
public:
    vector<vector<int>> g;
    double res;

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        g.resize(n+1);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        res = 0.0;
        dfs(1, -1, target, t, 1.0);
        return res;
    }

    void dfs(int i, int parent, int target, int t, double p) {
        int num_child = i == 1 ? g[i].size() : g[i].size()-1;
        if (i == target) {
            if (t == 0 || num_child == 0) res = p;
            return;
        }
        if (t == 0) return;
        for (int j : g[i]) {
            if (j == parent) continue;
            dfs(j, i, target, t-1, p/num_child);
        }
    }
};

int main() {

}
