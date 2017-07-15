#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  string solveEquation(string s) {
    int n = s.size();
    int coe = 0, con = 0;
    int num = 0, sign = 1, x = 0, left = 1;
    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i])) num = num*10 + s[i]-'0';
      else if (s[i] == 'x') {
        if (i == 0 || !isdigit(s[i-1])) num = 1;
        x = 1;
      }
      if (s[i] == '+' || s[i] == '-' || s[i] == '=' || i == n-1) {
        if (x) coe += num * sign * left;
        else con += num * sign * left;
        num = 0;
        sign = s[i] == '-' ? -1 : 1;
        x = 0;
        if (s[i] == '=') left = -1;
      }
    }
    if (coe == 0 && con == 0) return "Infinite solutions";
    if (coe == 0 && con != 0) return "No solution";
    return "x=" + to_string(-con/coe);
  }
};


int main() {
  Solution s;
  cout << s.solveEquation("0x=0") << endl;
  return 0;
}
