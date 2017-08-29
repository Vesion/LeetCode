#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<int> constructArray(int n, int k) {
    vector<int> a(n);
    int l = 1, r = n;
    for (int i = 0; i < k; ++i) a[i] = (i&1) ? r-- : l++; // generate k-1 different gap
    for (int i = k; i < n; ++i) a[i] = (k&1) ? l++ : r--; // generate the last gap 1, till the end
    return a;
  }
};


int main() {
  Solution s;
  auto r = s.constructArray(5, 1);
  for (auto& e : r) cout << e << " "; cout << endl; 
  return 0;
}
