#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  bool isOneBitCharacter(vector<int>& bits) {
    int i = 0, n = bits.size();
    bool res = false;
    while (i < n) {
      if (bits[i] == 1) {
        i += 2;
        res = false;
      } else {
        i += 1;
        res = true;
      }
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<int> b = {0,1,1,0};
  cout << s.isOneBitCharacter(b) << endl;
  return 0;
}
