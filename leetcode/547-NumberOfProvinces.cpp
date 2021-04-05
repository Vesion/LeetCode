#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> root;
    int count;
    int find(int x) {
        return x == root[x] ? x : root[x] = find(root[x]);
    }

    void link(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            root[rx] = ry;
            --count;
        }
    }
    int findCircleNum(vector<vector<int>>& connect) {
        int n = connect.size();
        root.resize(n); iota(root.begin(), root.end(), 0);
        count = n;
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
            if (connect[i][j]) link(i, j);
        }
        return count;
    }
};

int main() {
    return 0;
}
