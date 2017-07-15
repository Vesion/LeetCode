#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<int> price;
  vector<vector<int>> special;
  int m, n;
  vector<int> needs;
  int res;

  int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    this->price = price;
    this->special = special;
    this->needs = needs;
    this->m = needs.size(), this->n = special.size();
    this->res = INT_MAX;
    dfs(0, 0);
    return res;
  }

  void dfs(int k, int money) {
    if (k == n) {
      for (int i = 0; i < m; ++i) money += price[i]*needs[i];
      res = min(res, money);
      return;
    }
    dfs(k+1, money);
    auto& sp = special[k];
    int c = 1;
    while (true) {
      for (int i = 0; i < m; ++i) if (sp[i]*c > needs[i]) return;
      for (int i = 0; i < m; ++i) needs[i] -= c*sp[i];
      dfs(k+1, money+sp.back()*c);
      for (int i = 0; i < m; ++i) needs[i] += c*sp[i];
      ++c;
    }
  }
};


int main() {
  Solution s;
  vector<int> p = {9, 9};
  vector<vector<int>> sp = {{1,1,1}};
  vector<int> n = {2,2};
  cout << s.shoppingOffers(p, sp, n);
  return 0;
}
