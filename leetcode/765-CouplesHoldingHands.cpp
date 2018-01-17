#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// just naive swap
class Solution {
public:
  int minSwapsCouples(vector<int>& row) {
    int n = row.size();
    vector<int> id(n);
    for (int i = 0; i < n; ++i) id[row[i]] = i;
    int res = 0;
    for (int i = 0; i < n; i += 2) {
      int t = (row[i]%2 ? row[i]-1 : row[i]+1);
      if (row[i+1] != t) {
        int s = row[i+1];
        swap(row[i+1], row[id[t]]);
        swap(id[s], id[t]);
        ++res;
      }
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<int> r = {5,3,0,2,4,1};
  cout << s.minSwapsCouples(r) << endl;
  return 0;
}
