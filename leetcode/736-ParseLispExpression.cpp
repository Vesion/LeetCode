#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
  int evaluate(string expression) {
    int i = 0;
    return parse(expression, expression.size(), i, {});
  }

  int parse(string& s, int n, int& i, unordered_map<string, int> m) {
    int res = 0;
    if (s[i] == '(') ++i;
    if (s.substr(i, 3) == "add") { // add expr
      i += 4;
      int left = parse(s, n, i, m);
      ++i;
      int right = parse(s, n, i, m);
      res = left + right;
    } else if (s.substr(i, 4) == "mult") { // mult expr
      i += 5;
      int left = parse(s, n, i, m);
      ++i;
      int right = parse(s, n, i, m);
      res = left * right;
    } else if (s.substr(i, 3) == "let") { // let expr
      i += 4;
      while (i < n && s[i] != ')') {
        string var;
        if (isalpha(s[i])) while (i < n && isalnum(s[i])) var += s[i++];
        else { res = parse(s, n, i, m); break; }
        if (s[i] == ' ') {
          ++i;
          m[var] = parse(s, n, i, m);
          ++i;
        } else if (s[i] == ')') res = m[var];
      }
    } else if (isalpha(s[i])) { // assigned expr
      string var;
      while (i < n && isalnum(s[i])) var += s[i++];
      res = m[var];
    } else { // integer expr
      int sign = 1;
      if (s[i] == '-') { sign = -1; ++i; }
      while (i < n && isdigit(s[i])) res = res*10 + s[i++]-'0';
      res *= sign;
    }
    if (s[i] == ')') ++i;
    return res;
  }
};


int main() {
  Solution s;
  cout << s.evaluate("(add 1 -2)") << endl;
  cout << s.evaluate("(mult 3 (add 2 3))") << endl;
  cout << s.evaluate("(let x 2 (mult x 5))") << endl;
  cout << s.evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))") << endl;
  cout << s.evaluate("(let x 3 x 2 x)") << endl;
  cout << s.evaluate("(let x 1 y 2 x (add x y) (add x y))") << endl;
  cout << s.evaluate("(let x 2 (add (let x 3 (let x 4 x)) x))") << endl;
  cout << s.evaluate("(let a1 3 b2 (add a1 1) b2)") << endl;
  cout << s.evaluate("12") << endl;
  return 0;
}
