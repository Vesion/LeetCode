#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

// constexpr int N = 100; // the number of unique nodes

map<int, set<int>> graph;
map<int, int> indegrees;
set<int> visited;

map<int, set<int>> results;

set<int> dfs(int cur) {
  if (visited.count(cur)) return set<int>();
  visited.insert(cur);
  set<int> result;
  for (int child : graph[cur]) {
    auto child_result = dfs(child);
    result.insert(child_result.begin(), child_result.end());
  }
  results[cur] = result;
  return result;
}


int main() {
  for (auto p : indegrees) {
    if (p.second == 0) {
      dfs(p.first);
    }
  }
  return 0;
}
