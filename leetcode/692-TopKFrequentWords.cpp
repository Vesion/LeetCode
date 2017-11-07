#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <queue> 
using namespace std;

class Solution {
public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> c;
    for (auto& w : words) c[w]++;
    auto cmp = [](const pair<int,string>& p1, const pair<int,string>& p2) {
      if (p1.first == p2.first) return p1.second < p2.second; 
      return p1.first > p2.first;
    };
    priority_queue<pair<int,string>, vector<pair<int,string>>, decltype(cmp)> pq(cmp);
    for (auto& p : c) {
      pq.push({p.second, p.first});
      if ((int)pq.size() > k) pq.pop();
    }
    vector<string> res;
    while (!pq.empty()) {
      res.push_back(pq.top().second);
      pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};


int main() {
  return 0;
}
