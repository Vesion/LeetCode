#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  bool canTransform(string start, string end) {
    int n = start.size(), m = end.size();
    if (n != m) return false;
    int sl = 0, sx = 0, el = 0, ex = 0;
    for (char c : start) { if (c == 'L') ++sl; else if (c == 'X') ++sx; }
    for (char c : end) { if (c == 'L') ++el; else if (c == 'X') ++ex; }
    if (sl != el || sx != ex) return false;

    int i = 0, j = 0, x = 0;
    while (i < n && j < m) {
      while (i < n && start[i] != 'L') if (start[i++] != 'X') x = 0; else ++x;
      while (j < n && end[j] != 'L') ++j;
      if (i != j) {
        if (i < n && j < m && i > j && i-j <= x) swap(start[i], start[j]);
        else return false;
      }
      ++i; ++j;
    }

    i = n-1, j = m-1, x = 0;
    while (i >= 0 && j >= 0) {
      while (i >= 0 && start[i] != 'R') if (start[i--] != 'X') x = 0; else ++x;
      while (j >= 0 && end[j] != 'R') --j;
      if (i != j) {
        if (i >= 0 && j >= 0 && j > i && j-i <= x) swap(start[i], start[j]);
        else return false;
      }
      --i; --j;
    }
    return true;
  }
};


int main() {
  Solution s;
  cout << s.canTransform("XRLXLXXXLXRXXXLXLLXX", "XRXXLXXLXLRXXLXXLXXL") << endl;
  return 0;
}
