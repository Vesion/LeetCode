#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  string shortestCompletingWord(string licensePlate, vector<string>& words) {
    vector<int> m(26, 0);
    int cnt = 0;
    for (char c : licensePlate) if (isalpha(c)) { m[tolower(c)-'a']++; cnt++; }
    string res;
    for (string& w : words) {
      int x = cnt;
      auto cm = m;
      for (char c : w) if (cm[c-'a']-- > 0) --x;
      if (x == 0 && (res.empty() || w.size() < res.size())) res = w;
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<string> w = {"step", "steps", "stripe", "stepple"};
  cout << s.shortestCompletingWord("1s3 PSt", w) << endl;
  return 0;
}
