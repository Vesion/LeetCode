#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    auto it = lower_bound(arr.begin(), arr.end(), x);
    vector<int> res(k);
    auto left = it-1, right = it;
    for (int i = 0; i < k; ++i) {
      if (right == arr.end() || (left >= arr.begin() && abs(*left-x) <= abs(*right-x))) res[i] = *(left--);
      else res[i] = *(right++);
    }
    sort(res.begin(), res.end());
    return res;
  }
};


int main() {
  return 0;
}
