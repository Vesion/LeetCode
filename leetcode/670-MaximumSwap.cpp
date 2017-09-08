#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : use t[i] to store the largest number's position on the right of i, O(n) time O(n) space
class Solution_1 {
public:
  int maximumSwap(int num) {
    string s = to_string(num);
    int n = s.size();
    vector<int> t(n, 0);
    char maxc = 0; int j = n-1;
    for (int i = n-1; i >= 0; --i) {
      if (s[i] > maxc) {
        maxc = s[i];
        j = i;
      }
      t[i] = j;
    }
    for (int i = 0; i < n; ++i) {
      if (t[i] != i && s[i] != s[t[i]]) {
        swap(s[i], s[t[i]]);
        break;
      }
    }
    return stoi(s);
  }
};


// Solution 2 : use d[i] to store the most right position of digit i, O(9*n) time O(1) space
class Solution {
public:
  int maximumSwap(int num) {
    string s = to_string(num);
    int n = s.size();
    vector<int> d(10, -1);
    for (int i = 0; i < n; ++i) d[s[i]-'0'] = i;
    for (int i = 0; i < n; ++i) {
      for (int j = 9; j > s[i]-'0'; --j) {
        if (d[j] > i) {
          swap(s[i], s[d[j]]);
          return stoi(s);
        }
      }
    }
    return num;
  }
};


int main() {
  Solution s;
  cout << s.maximumSwap(98368) << endl;
  cout << s.maximumSwap(1993) << endl;
  return 0;
}
