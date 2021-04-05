#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxk = 0;
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            maxk = max(maxk, arr[i]);
            if (maxk == i) ++res;
        }
        return res;
    }
};


int main() {
  Solution s;
  vector<int> a = {2,0,1};
  cout << s.maxChunksToSorted(a) << endl;
  return 0;
}
