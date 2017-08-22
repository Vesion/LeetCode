#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// Solution : dfs + backtracking
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<bool>> f(10, vector<bool>(10, true));
        f[1][3] = f[1][7] = f[1][9] = 
        f[3][1] = f[3][7] = f[3][9] = 
        f[7][1] = f[7][3] = f[7][9] = 
        f[9][1] = f[9][3] = f[9][7] = 
        f[2][8] = f[8][2] = f[4][6] = f[6][4] = false;

        int res = 0;
        for (int i = m; i <= n; ++i) {
            res += dfs(i, 1, f, 1<<1) * 4; // 1, 3, 7, 9 are symmetric
            res += dfs(i, 2, f, 1<<2) * 4; // 2, 4, 6, 8 are symmetric
            res += dfs(i, 5, f, 1<<5);
        }
        return res;
    }
    
    int dfs(int n, int start, vector<vector<bool>>& f, int visited) {
        if (n == 1) return 1;
        int res = 0;
        for (int i = 1; i <= 9; ++i) {
            if (!(visited&(1<<i)) && (f[start][i] || (visited&(1<<((i+start)/2)))))
                res += dfs(n-1, i, f, visited|(1<<i));
        }
        return res;
    }
};


int main() {
    return 0;
}

