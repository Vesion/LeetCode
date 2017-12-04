#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if (image.empty() || image[sr][sc] == newColor) return image;
    auto res = image;
    dfs(res, sr, sc, image[sr][sc], newColor);
    return res;
  }

  void dfs(vector<vector<int>>& g, int i, int j, int c, int nc) {
    int m = g.size(), n = g[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] != c) return;
    g[i][j] = nc;
    dfs(g, i+1, j, c, nc);
    dfs(g, i-1, j, c, nc);
    dfs(g, i, j+1, c, nc);
    dfs(g, i, j-1, c, nc);
  }
};


int main() {
  return 0;
}
