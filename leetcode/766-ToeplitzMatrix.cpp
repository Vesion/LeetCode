#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// O(N) space
class Solution1 {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> di(m+n-1, -1);
        for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) {
            int k = i+n-1-j;
            if (di[k] == -1) di[k] = matrix[i][j];
            else if (di[k] != matrix[i][j]) return false;
        }
        return true;
    }
};


// O(1) space
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
