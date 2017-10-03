#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int repeatedStringMatch(string A, string B) {
    if (A.find(B) != string::npos) return 1;
    if ((A+A).find(B) != string::npos) return 2;
    auto n = A.size(), m = B.size();
    int c = 0;
    auto p = B.find(A);
    auto op = p;
    while (p != string::npos) {
      ++c;
      p += n;
      auto q = B.find(A, p);
      if (q == string::npos || q != p) break;
    }
    if (!c) return -1;
    if (op > 0 && (op > n || A.substr(n-op) != B.substr(0, op))) return -1;
    if (p < m && (m-p > n || A.substr(0, m-p) != B.substr(p))) return -1;
    return c + (op > 0) + (p < m);
  }
};

int main() {
  Solution s;
  cout << s.repeatedStringMatch("aba", "zzzzzzzabazzzzzzzzzz") << endl;
  return 0;
}
