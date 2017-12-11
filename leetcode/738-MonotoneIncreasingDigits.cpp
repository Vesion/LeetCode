#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

class Solution {
public:
  int monotoneIncreasingDigits(int N) { 
    string s = to_string(N);
    int n = s.size(), j = s.size();
    for (int i = n-1; i > 0; --i) {
      if (s[i] < s[i-1]) {
        j = i;
        --s[i-1];
      }
    }
    for (int i = j; i < n; ++i) s[i] = '9';
    return stoi(s);
  }
};


int main() {
  Solution s;
  cout << s.monotoneIncreasingDigits(20) << endl;
  return 0;
}
