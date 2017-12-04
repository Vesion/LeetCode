#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
using namespace std;

class Solution {
public:
  bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) { 
    unordered_map<string, unordered_set<string>> m;
    for (auto& p : pairs) {
      m[p.first].insert(p.second);
      m[p.second].insert(p.first);
    }
    if (words1.size() == words2.size()) return false;;
    for (int i = 0; i < (int)words1.size(); ++i) {
      if (words1[i] != words2[i] && (!m.count(words1[i]) || !m[words1[i]].count(words2[i]))) return false;
    }
    return true;
  }
};


int main() {
  return 0;
}
