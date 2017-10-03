#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  double knightProbability(int N, int K, int r, int c) {
    vector<vector<vector<double>>> dp(N, vector<vector<double>>(N, vector<double>(K+1, 0)));
    int go[8][2] = {{-2,-1}, {-2,1}, {-1,2}, {1, 2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}};
    double p = 1.0/8;
    dp[r][c][0] = 1;
    for (int k = 1; k <= K; ++k) {
      for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
        for (int d = 0; d < 8; ++d) {
          int oi = i+go[d][0], oj = j+go[d][1];
          if (oi < 0 || oi >= N || oj < 0 || oj >= N) continue;
          dp[i][j][k] += dp[oi][oj][k-1]*p;
        }
      }
    }
    double res = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) res += dp[i][j][K];
    return res;
  }
};


int main() {
  return 0;
}
