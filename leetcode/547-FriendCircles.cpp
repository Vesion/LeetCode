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
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        count = n;
        root.resize(n);
        iota(root.begin(), root.end(), 0);
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) if (M[i][j]) unionSet(i, j);
        }
        return count;
    }
};


int main() {
    return 0;
}
