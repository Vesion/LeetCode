#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> color;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.resize(n, -1);
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1 && !test(i, 0, graph)) return false;
        }
        return true;
    }

    bool test(int node, int c, const vector<vector<int>>& g) {
        color[node] = c;
        for (int nbr : g[node]) {
            if (color[nbr] == 1-c) continue;
            if (color[nbr] == c || !test(nbr, 1-c, g)) return false;
        }
        return true;
    }
};

int main() {

}