#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

// Solution 1 : trivial, O(L*N)
class Solution_1 {
public:
  int rotatedDigits(int N) {
    int res = 0;
    for (int i = 1; i <= N; ++i) if (isValid(i)) ++res;
    return res;
  }

  bool isValid(int num) {
    bool diff = false;
    while (num) {
      int x = num%10;
      if (x == 3 || x == 4 || x == 7) return false;
      if (x == 2 || x == 5 || x == 6 || x == 9) diff = true;
      num /= 10;
    }
    return diff;
  }
};


// Solution 2 : count, O(logN)
class Solution {
public:
  int valid_count[10] = {1,2,3,3,3,4,5,5,6,7}; // 0,1,2,5,6,8,9
  int exclude_count[10] = {1,2,2,2,2,2,2,2,3,3}; // 0,1,8
  bool is_valid[10] = {1,1,1,0,0,1,1,0,1,1}; // 0,1,2,5,6,8,9
  bool is_exclude[10] = {1,1,0,0,0,0,0,0,1,0}; // 0,1,8

  int rotatedDigits(int N) {
    string s = to_string(N);
    int len = s.size();
    bool exclude = true;
    int res = 0;
    for (int i = 0, j = len; i < len; ++i, --j) {
      if (s[i] == '0' && i != len-1) continue;
      int index = i == len-1 ? s[i]-'0' : s[i]-'0'-1;
      int c = valid_count[index] * pow(7, j-1);
      int e = exclude ? exclude_count[index] * pow(3, j-1) : 0;
      res += c-e;
      if (!is_valid[s[i]-'0']) break;
      exclude &= is_exclude[s[i]-'0'];
    }
    return res;
  }
};


int main() {
  Solution s;
  cout << s.rotatedDigits(10) << endl;
  return 0;
}
