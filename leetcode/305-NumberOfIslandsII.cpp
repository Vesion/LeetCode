#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// union find
// no need an extra m*n grid to record islands' position
// we use root[id] != -1 to judge if it's an island
class Solution {
private:
    vector<int> root;
    int count;
    
    int findRoot(int i) {
        if (root[i] != i) root[i] = findRoot(root[i]);
        return root[i];
    }
    
    void unionSet(int i, int j) {
        int ri = findRoot(i), rj = findRoot(j);
        if (ri != rj) {
            root[ri] = rj;
            --count;
        }
    }
    
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        if (positions.empty()) return {};
        root.resize(m*n, -1);
        count = 0;
        
        int go[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<int> res;
        for (auto& p : positions) {
            int id = p.first*n + p.second;
            root[id] = id;
            ++count;
            for (int d = 0; d < 4; ++d) {
                int nx = p.first+go[d][0], ny = p.second+go[d][1];
                int nid = nx*n + ny;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || root[nid] == -1) continue; 
                unionSet(id, nid);
            }
            res.push_back(count);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<pair<int,int>> p = {{0,1},{1,0},{1,2},{2,1},{0,2},{1,1}};
    auto r = s.numIslands2(3,3,p);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
