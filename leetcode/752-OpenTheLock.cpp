#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

// BFS
class Solution0 {
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

// Two-ends BFS, should have been faster than one-end, but unordered_set takes overhead
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s1, s2, sd;
        s1.insert("0000");
        s2.insert(target);
        for (const string& d : deadends) sd.insert(d);
        if (sd.count("0000")) return -1;

        int step = 0;
        while (!s1.empty() && !s2.empty()) {
            auto& from = s1.size() >= s2.size() ? s1 : s2;
            auto& to = s1.size() < s2.size() ? s1 : s2;
            unordered_set<string> snew;
            for (const string& s : from) {
                if (to.count(s)) return step;
                string ns = s;
                for (int i = 0; i < 4; ++i) {
                    char od = ns[i];
                    for (int d = -1; d <= 1; d += 2) {
                        ns[i] = (od-'0'+10+d)%10 + '0';
                        if (!sd.count(ns)) {
                            snew.insert(ns);
                            sd.insert(ns);
                        }
                        ns[i] = od;
                    }
                }
            }
            from.swap(snew);
            ++step;
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
