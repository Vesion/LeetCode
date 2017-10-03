#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int cur;
  int d[10] = {0};
  int path[4], res;

  string nextClosestTime(string time) {
    memset(d, 0, sizeof d);
    for (char&c : time) if (isdigit(c)) d[c-'0']++;
    cur = stoi(time.substr(0, 2))*60 + stoi(time.substr(3));
    res = INT_MAX;
    dfs(0);
    if (res == INT_MAX) {
      int i = 0;
      for (int j = 0; j < 10; ++j) if (d[j]) { i = j; break; }
      return string(2, '0'+i) + ":" + string(2, '0'+i);
    }
    return (res/60 < 10 ? "0" : "") + to_string(res/60) + ":" + (res%60 < 10 ? "0" : "") + to_string(res%60);
  }

  void dfs(int i) {
    if (i == 4) {
      int x = (path[0]*10+path[1])*60 + (path[2]*10+path[3]);
      if (path[0]*10+path[1] >= 24 || path[2]*10+path[3] >= 60) return;
      if (x > cur && x-cur < abs(res-cur)) res = x;
      return;
    }
    for (int j = 0; j < 10; ++j) {
      if (d[j]) {
        path[i] = j;
        dfs(i+1);
      }
    }
  }
};


int main() {
  Solution s;
  cout << s.nextClosestTime("23:59") << endl;
  cout << s.nextClosestTime("01:32") << endl;
  cout << s.nextClosestTime("20:48") << endl;
  cout << s.nextClosestTime("00:13") << endl;
  return 0;
}
