#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int m, n;

    int shortestBridge(vector<vector<int>>& A) {
        m = A.size(), n = A[0].size();
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            if (A[i][j]) {
                discover(A, i, j);
                return reach2(A);
            }
        }
        return 0;
    }

    const int go[5] = {1, 0, -1, 0, 1};

    // DFS to flood fill
    void discover(vector<vector<int>>& A, int i, int j) {
        A[i][j] = 2;
        for (int d = 0; d < 4; ++d) {
            int ni = i+go[d], nj = j+go[d+1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || A[ni][nj] != 1) continue;
            discover(A, ni, nj);
        }
    }

    // BFS to find the shortes path
    int reach2(vector<vector<int>>& A) {
        using S = tuple<int,int>;
        queue<S> q;
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j)
            if (A[i][j] == 2) q.push({i, j});
        int res = 0;
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                auto [i,j] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int ni = i+go[d], nj = j+go[d+1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n || A[ni][nj] == 2) continue;
                    if (A[ni][nj] == 1) return res;
                    q.push({ni, nj});
                    A[ni][nj] = 2;
                }
            }
            ++res;
        }
        return 0;
    }
};

int main() {

}
