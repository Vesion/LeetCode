#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

class Solution {
public:
    int movingCount(int k, int m, int n) {
        if (k < 0) return 0;
        vector<vector<bool>> f(m, vector<bool>(n, false));
        int go[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        auto valid = [&k](int i, int j) {
        	int r = 0;
            while (i) { r += i%10; i /= 10; }
            while (j) { r += j%10; j /= 10; }
            return r <= k;
        };
        queue<pair<int,int>> q;
        q.push({0, 0});
        f[0][0] = true;
        int res = 0;
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second; q.pop();
            ++res;
            for (int d = 0; d < 4; ++d) {
                int ni = i+go[d][0], nj = j+go[d][1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n || f[ni][nj] || !valid(ni, nj)) continue;
                q.push({ni, nj});
                f[ni][nj] = true;
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
