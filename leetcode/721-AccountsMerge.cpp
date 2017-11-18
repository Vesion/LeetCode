#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
#include <unordered_map> 
using namespace std;

// Union Find
class Solution {
public:
  unordered_map<string, string> root;
  unordered_map<string, string> user;
  unordered_map<string, set<string>> unions;

  string findRoot(const string& s) {
    if (s != root[s]) root[s] = findRoot(root[s]);
    return root[s];
  }

  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < (int)accounts[i].size(); ++j) {
        root[accounts[i][j]] = accounts[i][j];
        user[accounts[i][j]] = accounts[i][0];
      }
    }

    for (int i = 0; i < n; ++i) {
      string r = findRoot(accounts[i][1]);
      for (int j = 2; j < (int)accounts[i].size(); ++j) {
        root[findRoot(accounts[i][j])] = r;
      }
    }


    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < (int)accounts[i].size(); ++j) {
        unions[findRoot(accounts[i][j])].insert(accounts[i][j]);
      }
    }

    vector<vector<string>> res;
    for (auto& p : unions) {
      vector<string> emails(p.second.begin(), p.second.end());
      emails.insert(emails.begin(), user[p.first]);
      res.push_back(emails);
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<vector<string>> a = { { "David","David0@m.co","David1@m.co" },{ "David","David3@m.co","David4@m.co" },{ "David","David4@m.co","David5@m.co" },{ "David","David2@m.co","David3@m.co" },{ "David","David1@m.co","David2@m.co" } };
  auto r = s.accountsMerge(a);
  for (auto& i : r) {
    for (auto& j : i) { cout << j << " "; }
    cout << endl;
  }
  return 0;
}
