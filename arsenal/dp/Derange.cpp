#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// D[n] = (n-1)*(D[n-1]+D[n-2])
class Solution {
public:
  int findDerangement(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    int r1 = 0, r2 = 1;
    for (int i = 3; i <= n; ++i) {
      int t = (i-1)*(r1+r2);
      r1 = r2;
      r2 = t;
    }
    return r2;
  }
};


int main() {
  return 0;
}
