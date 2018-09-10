#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
#include <stack> 
using namespace std;
using ll = long long;

// Problem:
//    Validate a string of parentheses
// Solution:
//    Stack or counting
class Solution {
public:
  bool validate(string s) {
    int p = 0;
    for (char c : s) {
      if (c == '(') ++p;
      else --p;
      if (p < 0) return false;
    }
    return p == 0;
  }
};


// Problem:
//    Give a valid string of parentheses, remove from left to right, each time remove a pair to keep valid, how many ways to remove all?
// Solution:
//    Counting
class Solution_rm {
public:
  int removePairs(string s) {
    int res = 1;
    int n = s.size();
    int t = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++t;
            res *= t;
        } else --t;
    }
    return res;
  }
};


int main() {
  return 0;
}

