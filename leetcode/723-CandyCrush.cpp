#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1
class Solution_1 {
public:
  vector<vector<int>> candyCrush(vector<vector<int>>& board) {
    int m = board.size(), n = board[0].size();
    bool f = false;
    while (!f) {
      f = true;
      vector<vector<int>> crush(m, vector<int>(n, 0));
      for (int i = 0; i < m; ++i) {
        vector<int> left(n, 0);
        for (int j = 1; j < n; ++j) if (board[i][j] == board[i][j-1]) left[j] = left[j-1]+1;
        int right = 0;
        for (int j = n-1; j >= 0; --j) {
          if (j < n-1 && board[i][j] == board[i][j+1]) ++right;
          else right = 0;
          if (left[j]+right >= 2) crush[i][j] = 1;
        }
      }

      for (int j = 0; j < n; ++j) {
        vector<int> top(m, 0);
        for (int i = 1; i < m; ++i) if (board[i][j] == board[i-1][j]) top[i] = top[i-1]+1;
        int bottom = 0;
        for (int i = m-1; i >= 0; --i) {
          if (i < m-1 && board[i][j] == board[i+1][j]) ++bottom;
          else bottom = 0;
          if (top[i]+bottom >= 2) crush[i][j] = 1;
        }
      }

      vector<int> drop(n, 0);
      for (int i = m-1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
          if (crush[i][j] && board[i][j] != 0) {
            f = false;
            drop[j]++;
          } else {
            board[i+drop[j]][j] = board[i][j];
          }
        }
      }

      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (drop[j]) {
            board[i][j] = 0;
            --drop[j];
          }
        }
      }
    }
    return board;
  }
};


// Solution 2
class Solution {
public:
  vector<vector<int>> candyCrush(vector<vector<int>>& b) {
    int n = b.size(), m = b[0].size();
    while (true) {
      vector<pair<int,int>> vp;
      for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (b[i][j]) {
        int i0 = i, i1 = i, j0 = j, j1 = j;
        while (i1 < n &&  i1 < i + 3 && b[i1][j] == b[i][j]) ++i1;
        while (i0 >= 0 && i0 > i - 3 && b[i0][j] == b[i][j]) --i0;
        while (j1 < m && j1 < j + 3 && b[i][j1] == b[i][j]) ++j1;
        while (j0 >= 0 && j0 > j - 3 && b[i][j0] == b[i][j]) --j0;
        if (i1 - i0 >3 || j1 -j0 > 3) vp.push_back({i,j});
      }
      if (vp.empty()) break;
      for (auto p:vp) b[p.first][p.second] = 0;
      for (int j = 0; j < m; ++j) {
        int t = n-1;
        for (int i = n-1; i >=0; --i) if (b[i][j]) swap(b[i][j],b[t--][j]);
      }
    }
    return b;
  }
};


int main() {
  Solution s;
  vector<vector<int>> b = { { 110,5,112,113,114 },{ 210,211,5,213,214 },{ 310,311,3,313,314 },{ 410,411,412,5,414 },{ 5,1,512,3,3 },{ 610,4,1,613,614 },{ 710,1,2,713,714 },{ 810,1,2,1,1 },{ 1,1,2,2,2 },{ 4,1,4,4,1014 } };
  auto r = s.candyCrush(b);
  for (auto& i : r) {
    for (auto& j : i) { cout << j << " "; }
    cout << endl;
  }
  return 0;
}
