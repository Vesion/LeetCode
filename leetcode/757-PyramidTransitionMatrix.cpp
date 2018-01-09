#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// dfs
class Solution {
public:
  vector<int> m[26][26];

  bool pyramidTransition(string bottom, vector<string>& allowed) { 
    vector<int> s;
    for (char c : bottom) s.push_back(c-'A');
    for (auto& t : allowed) m[t[0]-'A'][t[1]-'A'].push_back(t[2]-'A');
    vector<int> c;
    return dfs(s, c);
  }

  bool dfs(vector<int>& below, vector<int>& cur) {
    if (below.size() == 1) return true;
    if (cur.size() == below.size()-1) {
      vector<int> c;
      return dfs(cur, c);
    }
    int l = below[cur.size()], r = below[cur.size()+1];
    for (int x : m[l][r]) {
      cur.push_back(x);
      if (dfs(below, cur)) return true;
      cur.pop_back();
    }
    return false;
  }
};


int main() {
  Solution s;
  vector<string> a = {"BCE","BCF","ABA","CDA","AEG","FAG","GGG"};
  cout << s.pyramidTransition("ABCD", a) << endl;
  return 0;
}
