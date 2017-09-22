#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  bool validPalindrome(string s) {
    int n = s.size();
    int i = 0, j = n-1;
    int d = 0;
    while (i <= j) {
      if (s[i] == s[j]) { ++i; --j; }
      else if (!d) { ++i; ++d; }
      else break;
    }
    if (i >= j) return true;
    i = 0, j = n-1, d = 0;
    while (i <= j) {
      if (s[i] == s[j]) { ++i; --j; }
      else if (!d) { --j; ++d; }
      else break;
    }
    return i >= j;
  }
};


int main() {
  return 0;
}
