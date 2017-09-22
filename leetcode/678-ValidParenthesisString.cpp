#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  bool checkValidString(string s) {
    int n = s.size();
    int p = 0, a = 0;
    for (int i = 0; i < n; ++i) { // check form left to right
      if (s[i] == '(') ++p;
      else if (s[i] == ')') --p;
      else ++a;
      if (p < 0) {
        if (a) { --a; ++p; }
        else return false;
      }
    }
    p = a = 0;
    for (int i = n-1; i >= 0; --i) { // check from right to left
      if (s[i] == ')') ++p;
      else if (s[i] == '(') --p;
      else ++a;
      if (p < 0) {
        if (a) { --a; ++p; }
        else return false;
      }
    }
    return true;
  }
};


int main() {
  Solution s;
  cout << s.checkValidString("()") << endl;
  cout << s.checkValidString("(*)") << endl;
  cout << s.checkValidString("(*))") << endl;
  cout << s.checkValidString("((()))()(())(*()()())**(())()()()()((*()*))((*()*)") << endl;
  return 0;
}
