#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return {0};
        if (n == 2) return {0, 1};
        vector<vector<int>> graph(n);
        vector<int> indegrees(n, 0);
        vector<bool> hasDeleted(n, false);
        for (auto& e : edges) {
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
            indegrees[e.first]++;
            indegrees[e.second]++;
        }

        // delete leaves level by level
        vector<int> cur, next;
        for (int i = 0; i < n; ++i) if (indegrees[i] == 1) cur.push_back(i);
        while (true) {
            for (int leaf : cur) {
                indegrees[leaf] = 0;
                for (int nbr : graph[leaf]) if (--indegrees[nbr] == 1) next.push_back(nbr);
            }
            if (next.empty()) return cur;
            cur = next;
            next.clear();
        }
        return {}; // never
    }
};

int main() {
    Solution s;
    vector<pair<int,int>> e = {{0,1}};
    auto r = s.findMinHeightTrees(2, e);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}

