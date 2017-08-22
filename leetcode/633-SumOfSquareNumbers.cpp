#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

// two pointers
class Solution {
public:
  bool judgeSquareSum(int c) {
    int left = 0, right = sqrt(c);
    while (left <= right) {
      int t = left*left + right*right;
      if (t > c) --right;
      else if (t < c) ++left;
      else return true;
    }
    return false;
  }
};


int main() {
  return 0;
}
