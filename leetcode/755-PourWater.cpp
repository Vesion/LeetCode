#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<int> pourWater(vector<int>& heights, int V, int K) {
    auto res = heights;
    int n = heights.size();
    while (V--) {
      int t = K;
      for (int i = t-1; i >= 0; --i) {
        if (res[i] < res[i+1]) t = i;
        else if (res[i] > res[i+1]) break;
      }
      if (t < K) { ++res[t]; continue; }
      for (int i = t+1; i < n; ++i) {
        if (res[i] < res[i-1]) t = i;
        else if (res[i] > res[i-1]) break;
      }
      ++res[t];
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<int> h = {3,1,3};
  auto r = s.pourWater(h, 5, 1);
  for (auto& e : r) cout << e << " "; cout << endl; 
  return 0;
}
