#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int numJewelsInStones(string J, string S) {
    int m[256] = {0};
    for (char c : J) m[(int)c] = 1;
    int res = 0;
    for (char c : S) if (m[(int)c]) ++res;
    return res;
  }
};


int main() {
  return 0;
}
