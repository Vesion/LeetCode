#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    vector<string> res;
    dfs(S, 0, res);
    return res;
  }

  void dfs(string& s, int i, vector<string>& res) {
    if (i == (int)s.size()) {
      res.push_back(s);
      return;
    }
    dfs(s, i+1, res);
    char x = s[i];
    if (islower(s[i])) { s[i] = toupper(s[i]); dfs(s, i+1, res); }
    else if (isupper(s[i])) { s[i] = tolower(s[i]); dfs(s, i+1, res); }
    s[i] = x;
  }
};


int main() {
  return 0;
}
