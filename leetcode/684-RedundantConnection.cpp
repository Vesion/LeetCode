#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> 
#include <string>
using namespace std;

class Solution {
private:
  vector<int> root;
  int findRoot(int i) {
    if (i != root[i]) root[i] = findRoot(root[i]);
    return root[i];
  }

public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    root.resize(n+1);
    iota(root.begin(), root.end(), 0);
    for (auto& e : edges) {
      int u = e[0], v = e[1];
      int ru = findRoot(u), rv = findRoot(v);
      if (ru == rv) return e;
      root[ru] = rv;
    }
    return {};
  }
};


int main() {
  return 0;
}
