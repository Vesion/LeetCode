#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<int>> g;
    vector<int> dist;
    vector<int> count;
    int n;

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        g.resize(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dist.resize(n, 0);
        count.resize(n, 1);
        post(0, -1);
        pre(0, -1);
        return dist;
    }

    // to get:
    // 1. result sum distance of root(0)
    // 2. count of child nodes including itself of each node
    void post(int root, int parent) {
        for (int child : g[root]) {
            if (child == parent) continue;
            post(child, root);
            dist[root] += dist[child] + count[child];
            count[root] += count[child];
        }
    }

    void pre(int root, int parent) {
        for (int child : g[root]) {
            if (child == parent) continue;
            dist[child] = dist[root] - count[child] + n - count[child];  // beautiful
            pre(child, root);
        }
    }
};

int main() {

}