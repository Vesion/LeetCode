#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
using namespace std;

class Solution {
public:
  string countOfAtoms(string formula) {
    int i = 0;
    auto r = parse(formula, i);
    string res;
    for (auto& p : r) res += p.first + (p.second > 1 ? to_string(p.second) : "");
    return res;
  }

  map<string, int> parse(string& s, int& i) {
    map<string, int> m;
    int n = s.size();
    while (i < n) {
      if (isupper(s[i])) {
        string a(1, s[i++]);
        while (i < n && islower(s[i])) a += s[i++];
        int c = (i < n && !isdigit(s[i]));
        while (i < n && isdigit(s[i])) c = c*10 + (s[i++]-'0');
        m[a] += c;
      } else if (s[i] == '(') {
        auto t = parse(s, ++i);
        int c = (i < n && !isdigit(s[i]));
        while (i < n && isdigit(s[i])) c = c*10 + (s[i++]-'0');
        for (auto& p : t) m[p.first] += p.second*c; 
      } else if (s[i] == ')') {
        ++i;
        break;
      }
    }
    return m;
  }
};


int main() {
  Solution s;
  cout << s.countOfAtoms("K4(ON(SO3)2)2") << endl;
  return 0;
}
