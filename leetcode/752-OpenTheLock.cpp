#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
#include <unordered_set> 
using namespace std;

class Solution {
public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> m(deadends.begin(), deadends.end());
    if (m.count("0000")) return -1;
    if (target == "0000") return 0;
    queue<string> q;
    q.push("0000");
    int res = 0;
    while (!q.empty()) {
      int len = q.size();
      ++res;
      while (len--) {
        string t = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
          char x = t[i];
          for (int d : {-1,1}) {
            t[i] = (x-'0'+d+10)%10 + '0';
            if (t == target) return res;
            if (!m.count(t)) { q.push(t); m.insert(t); }
          }
          t[i] = x;
        }
      }
    }
    return -1;
  }
};


int main() {
  Solution s;
  vector<string> d = {"8887","8889","8878","8898","8788","8988","7888","9888"};
  cout << s.openLock(d, "8888") << endl;
  return 0;
}
