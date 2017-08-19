#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Learn to see the key point of problem.
// This problem equals to converting decimal to 9-based number.
class Solution {
public:
  int newInteger(int n) {
    int res = 0, base = 1;
    while (n) {
      res += n%9 * base;
      n /= 9;
      base *= 10;
    }
    return res;
  }
};


int main() {
  return 0;
}
