#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// same to 785-IsGraphBipartite
class Solution {
public:
    vector<vector<int>> g;
    vector<int> color;

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        g.resize(n+1);
        color.resize(n+1, -1);
        for (const auto& a : dislikes) {
            g[a[0]].push_back(a[1]);
            g[a[1]].push_back(a[0]);
        }
        for (int i = 1; i <= n; ++i) {
            if (color[i] == -1 && !dfs(i, 0)) return false;
        }
        return true;
    }

    bool dfs(int i, int c) {
        color[i] = c;
        for (int j : g[i]) {
            if (color[j] == 1-c) continue;
            if (color[j] == c || !dfs(j, 1-c)) return false;
        }
        return true;
    }
};

int main() {
}
