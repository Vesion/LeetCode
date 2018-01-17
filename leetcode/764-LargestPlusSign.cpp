#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
    vector<vector<int>> g(N, vector<int>(N, 1));
    for (auto& p : mines) g[p[0]][p[1]] = 0;
    vector<vector<int>> down(N, vector<int>(N, 0));
    for (int i = N-1; i >= 0; --i) for (int j = 0; j < N; ++j)
      if (g[i][j]) down[i][j] = 1 + (i == N-1 ? 0 : down[i+1][j]);
    vector<int> up(N, 0);
    int res = 0;
    for (int i = 0; i < N; ++i) {
      vector<int> left(N, 0);
      for (int j = 0; j < N; ++j) {
        if (g[i][j]) {
          ++up[j];
          left[j] = 1 + (j == 0 ? 0 : left[j-1]);
        } else up[j] = 0;
      }
      int right = 0;
      for (int j = N-1; j >= 0; --j) {
        if (g[i][j]) {
          ++right;
          res = max(res, min(min(left[j], right), min(up[j], down[i][j])));
        } else right = 0;
      }
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<vector<int>> m = {{4,2}};
  cout << s.orderOfLargestPlusSign(5, m) << endl;
  return 0;
}
