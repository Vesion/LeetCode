#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
private:
  unordered_map<string,string> root;

  string findRoot(string& s) {
    if (!root.count(s)) return root[s] = s;
    if (root[s] != s) root[s] = findRoot(root[s]);
    return root[s];
  }

public:
  bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
    for (auto& p : pairs) {
      auto p1 = findRoot(p.first), p2 = findRoot(p.second);
      if (p1 != p2) root[p1] = p2;
    }
    if (words1.size() != words2.size()) return false;
    for (int i = 0; i < (int)words1.size(); ++i) {
      if (words1[i] != words2[i] && findRoot(words1[i]) != findRoot(words2[i])) return false;
    }
    return true;
  }
};


int main() {
  return 0;
}
