#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty()) return true;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
      int x = i, y = 0, a = matrix[x][y];
      while (x < m && y < n) if (matrix[x++][y++] != a) return false;
    }
    for (int j = 1; j < n; ++j) {
      int x = 0, y = j, a = matrix[x][y];
      while (x < m && y < n) if (matrix[x++][y++] != a) return false;
    }
    return true;
  }
};


int main() {
  return 0;
}
