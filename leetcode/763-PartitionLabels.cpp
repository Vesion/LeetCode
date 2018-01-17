#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    int n = s.size(), last[26] = {-1};
    for (int i = 0; i < n; ++i) last[s[i]-'a'] = i;
    vector<int> res;
    int start = 0, end = 0;
    for (int i = 0; i < n; ++i) {
      end = max(end, last[s[i]-'a']);
      if (i == end) {
        res.push_back(end-start+1);
        start = i+1;
      }
    }
    return res;
  }
};


int main() {
  Solution s;
  auto r = s.partitionLabels("ababcbacadefegdehijhklij");
  for (auto& e : r) cout << e << " "; cout << endl; 
  return 0;
}
