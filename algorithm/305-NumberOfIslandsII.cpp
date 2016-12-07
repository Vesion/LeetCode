#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        if (m == 0 || n == 0 || positions.empty()) return {};
        root.resize(m*n);
        count = 0;
        vector<int> res;
        vector<vector<int>> grid(m, vector<int>(n, 0));

        int go[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (auto& p : positions) {
            int i = p.first, j = p.second;
            ++count;
            grid[i][j] = 1;
            int id = i*n + j;
            root[id] = id; 
            for (int d = 0; d < 4; ++d) {
                int ni = i+go[d][0], nj = j+go[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) unionSet(id, ni*n+nj);
            }
            res.push_back(count);
        }
        return res;
    }

    vector<int> root;
    int count;

    void unionSet(int i, int j) {
        int ri = findRoot(i), rj = findRoot(j);
        if (ri != rj) {
            root[ri] = rj;
            --count;
        }
    }

    int findRoot(int i) {
        if (root[i] == i) return root[i];
        root[i] = findRoot(root[i]);
        return root[i];
    }
};

int main() {
    Solution s;
    vector<pair<int,int>> p = {{0,1},{1,0},{1,2},{2,1},{0,2},{1,1}};
    auto r = s.numIslands2(3,3,p);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
