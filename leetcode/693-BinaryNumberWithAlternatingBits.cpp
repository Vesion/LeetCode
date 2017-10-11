#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  bool hasAlternatingBits(int n) {
    bool f = n&1;
    n >>= 1;
    while (n) {
      if (!(f ^ (n&1))) return false;
      f = n&1;
      n >>= 1;
    }
    return true;
  }
};


int main() {
  Solution s;
  return 0;
}
