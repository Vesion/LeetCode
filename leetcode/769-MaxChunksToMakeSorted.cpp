#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    vector<int> rightMin(n);
    for (int i = n-1; i >= 0; --i) rightMin[i] = i == n-1 ? arr[i] : min(arr[i], rightMin[i+1]);
    vector<int> leftMax(n);
    for (int i = 0; i < n; ++i) leftMax[i] = i == 0 ? arr[i] : max(arr[i], leftMax[i-1]);
    int res = 1;
    for (int i = 0; i < n-1; ++i) if (leftMax[i] <= rightMin[i+1]) ++res;
    return res;
  }
};


int main() {
  Solution s;
  vector<int> a = {2,0,1};
  cout << s.maxChunksToSorted(a) << endl;
  return 0;
}
