#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    if (M.empty()) return M;
    int m = M.size(), n = M[0].size();
    vector<vector<int>> res(m, vector<int>(n, 0));
    int go[9][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,0}, {0,1}, {1,-1}, {1,0}, {1,1}};
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int t = 0, c = 0;
        for (int d = 0; d < 9; ++d) {
          int ni = i+go[d][0], nj = j+go[d][1];
          if (ni >= 0 && ni < m && nj >= 0 && nj < n) { t += M[ni][nj]; c++; }
        }
        res[i][j] = t/c;
      }
    }
    return res;
  }
};


int main() {
  return 0;
}
