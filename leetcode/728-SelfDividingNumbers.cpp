#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<int> selfDividingNumbers(int left, int right) { 
    vector<int> res;
    for (int i = left; i <= right; ++i) {
      if (check(i)) res.push_back(i);
    }
    return res;
  }

  bool check(int num) {
    int t = num;
    while (t) {
      if (t%10 == 0 || num % (t%10)) return false;
      t /= 10;
    }
    return true;
  }
};


int main() {
  return 0;
}
