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
    unordered_map<string,string> root;

    string find(const string& x) {
        if (root[x] != x) root[x] = find(root[x]);
        return root[x];
    }
    void link(const string& x, const string& y) {
        const string& rx = find(x);
        const string& ry = find(y);
        if (rx != ry) root[ry] = rx;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, string> user;
        for (const auto& account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                root[account[i]] = account[i];
                user[account[i]] = account[0];
            }
        }
        for (const auto& account : accounts) {
            for (int i = 2; i < account.size(); ++i) {
                link(account[1], account[i]);
            }
        }

        unordered_map<string, set<string>> group;
        for (const auto& account : accounts) {
            for (int i = 1; i < account.size(); ++i) {
                group[find(account[i])].insert(account[i]);
            }
        }

        vector<vector<string>> res;
        for (const auto& p : group) {
            vector<string> r;
            const string& name = user[p.first];
            r.push_back(name);
            for (const string& email : p.second) r.push_back(email);
            res.push_back(move(r));
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
