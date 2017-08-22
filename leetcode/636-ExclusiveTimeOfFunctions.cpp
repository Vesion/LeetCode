#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
#include <sstream> 
using namespace std;

class Solution {
public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> res(n, 0);
    stack<pair<int,int>> st;
    for (string& log : logs) {
      int id, f, t;
      parse(log, id, f, t);
      if (f) {
        if (!st.empty()) res[st.top().first] += t-st.top().second;
        st.push({id, t});
      }
      else {
        int s = st.top().second; st.pop();
        res[id] += t-s+1;
        if (!st.empty()) st.top().second = t+1;
      }
    }
    return res;
  }

  void parse(const string& l, int& id, int& f, int& t) {
    auto p = l.find(':', 0);
    id = stoi(l.substr(0, p));
    f = l[p+1] == 's';
    p = l.find(':', p+1);
    t = stoi(l.substr(p+1));
  }
};


int main() {
  Solution s;
  vector<string> l = { "0:start:0","1:start:2","1:end:5","0:end:6" };
  auto r = s.exclusiveTime(2, l);
  for (auto& e : r) cout << e << " "; cout << endl; 
  return 0;
}
