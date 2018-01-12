#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
#include <unordered_set> 
using namespace std;

// https://discuss.leetcode.com/topic/114813/easy-dfs
class Solution {
public:
  string crackSafe(int n, int k) {
    string res(n, '0');
    unordered_set<string> visited;
    visited.insert(res);
    dfs(n, k, pow(k, n), res, visited);
    return res;
  }

  bool dfs(int n, int k, size_t target, string& res, unordered_set<string>& visited) {
    if (visited.size() == target) return true;
    string prev = res.substr(res.size()-n+1);
    for (int i = 0; i < k; ++i) {
      string next = prev + to_string(i);
      if (!visited.count(next)) {
        res += to_string(i);
        visited.insert(next);
        if (dfs(n, k, target, res, visited)) return true;
        else {
          visited.erase(next);
          res.pop_back();
        }
      }
    }
    return false;
  }
};


int main() {
  Solution s;
  cout << s.crackSafe(2, 10) << endl;
  return 0;
}
