#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

class Solution {
public:
  vector<string> removeComments(vector<string>& source) {
    string s; for (string& l : source) s += l + '\n'; s.pop_back();
    string r;
    int i = 0, n = s.size();
    bool line = false, block = false;
    while (i < n) {
      if (s[i] == '/' && s[i+1] == '/' && !block && !line) { line = true; i += 2; continue; }
      if (s[i] == '/' && s[i+1] == '*' && !line && !block) { block = true; i += 2; continue; }
      if (line && s[i] == '\n') { line = false; }
      if (block && s[i] == '*' && s[i+1] == '/') { block = false; i += 2; continue; }
      if (!line && !block) r += s[i];
      ++i;
    }
    vector<string> res;
    istringstream in(r);
    string l;
    while (getline(in, l, '\n')) if (!l.empty()) res.push_back(l);
    return res;
  }
};


int main() {
  Solution s;
  vector<string> c = { "a//*b/*/c","blank","d/*/e/*/f" };
  auto r = s.removeComments(c);
  for (auto& e : r) cout << e << endl; cout << endl; 
  return 0;
}
