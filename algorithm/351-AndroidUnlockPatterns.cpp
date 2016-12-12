#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// Solution 1 : dfs + backtracking
class Solution {
public:
    vector<vector<bool>> f;
    int visited; // using bitmap as visited to speed up

    int numberOfPatterns(int m, int n) {
        f.resize(10, vector<bool>(10, true));
        f[1][3] = f[1][7] = f[1][9] = f[2][8] = f[3][1] = f[3][7] = f[3][9] = false;
        f[4][6] = f[6][4] = false;
        f[7][1] = f[7][3] = f[7][9] = f[8][2] = f[9][1] = f[9][3] = f[9][7] = false;

        visited = 0;
        int res = 0;
        for (int i = m; i <= n; ++i) {
            res += dfs(1, i) * 4; // 1, 3, 7, 9 are symmetric
            res += dfs(2, i) * 4; // 2, 4, 6, 8 are symmetric
            res += dfs(5, i);     // 5
        }
        return res;
    }

    int dfs(int cur, int rest) {
        if (rest == 1) return 1;
        visited |= (1 << cur);
        int res = 0;
        for (int i = 1; i <= 9; ++i) {
            if (!((visited >> i) & 1) && (f[cur][i] || (visited >> (cur+i)/2) & 1))
                res += dfs(i, rest-1);
        }
        visited ^= (1 << cur);
        return res;
    }
};

int main() {
    Solution s;
    cout << s.numberOfPatterns(1, 3) << endl;
    return 0;
}

