#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : O(n) time O(n) space
class Solution_1 {
public:
  int countBinarySubstrings(string s) {
    int n = s.size();
    vector<int> left(n, 0), right(n, 0);
    int c = 0;
    for (int i = 0; i < n; ++i) {
      if (i == 0 || s[i] == s[i-1]) ++c;
      else c = 1;
      left[i] = c;
    }
    c = 0;
    for (int i = n-1; i >= 0; --i) {
      if (i == n-1 || s[i] == s[i+1]) ++c;
      else c = 1;
      right[i] = c;
    }
    int res = 0;
    for (int i = 1; i < n; ++i) {
      if (s[i] != s[i-1]) res += min(left[i-1], right[i]);
    }
    return res;
  }
};


// Solution 2 : O(n) time O(1) space
class Solution {
public:
  int countBinarySubstrings(string s) {
    int n = s.size();
    int curLen = 1, preLen = 0, res = 0;
    for (int i = 1; i < n; ++i) {
      if (s[i] == s[i-1]) ++curLen;
      else {
        preLen = curLen;
        curLen = 1;
      }
      if (preLen >= curLen) ++res;
    }
    return res;
  }
};


int main() {
  Solution s;
  cout << s.countBinarySubstrings("00110011") << endl;
  return 0;
}
