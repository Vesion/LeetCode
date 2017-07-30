#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// same with 435
class Solution {
public:
  int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), [](const vector<int>& v1, const vector<int>& v2) { return v1[0] < v2[0]; });
    int end = INT_MIN, res = 0;
    for (auto& p : pairs) {
      if (p[0] > end) {
        ++res;
        end = p[1];
      } else end = min(end, p[1]);
    }
    return res;
  }
};


int main() {
  return 0;
}
