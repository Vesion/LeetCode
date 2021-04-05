#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// DFS, find the largest weight path
class Solution {
public:
    vector<vector<int>> g;

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        g.resize(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) g[manager[i]].push_back(i);
        }
        return dfs(headID, informTime);
    }

    int dfs(int i, const vector<int>& t) {
        int res = 0;
        for (int j : g[i]) {
            res = max(res, dfs(j, t) + t[i]);
        }
        return res;
    }
};

// BFS
class Solution1 {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& t) {
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) g[manager[i]].push_back(i);
        }

        queue<pair<int,int>> pq;
        pq.push({headID, 0});
        int res = 0;
        while (!pq.empty()) {
            auto s = pq.front(); pq.pop();
            int i = s.first, w = s.second;
            res = max(res, w);
            for (int j : g[i]) {
                pq.push({j, w + t[i]});
            }
        }
        return res;
    }
};

int main() {
}
