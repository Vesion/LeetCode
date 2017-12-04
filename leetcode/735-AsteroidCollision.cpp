#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// stack
class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) { 
    int n = asteroids.size();
    vector<int> res;
    stack<int> right;
    for (int i = 0; i < n; ++i) {
      if (asteroids[i] >= 0) right.push(asteroids[i]);
      else {
        while (!right.empty() && -asteroids[i] > right.top()) right.pop();
        if (!right.empty() && -asteroids[i] == right.top()) { right.pop(); continue; }
        if (right.empty()) res.push_back(i);
      }
    }
    stack<int> left;
    for (int i = n-1; i >= 0; --i) {
      if (asteroids[i] <= 0) left.push(-asteroids[i]);
      else {
        while (!left.empty() && asteroids[i] > left.top()) left.pop();
        if (!left.empty() && asteroids[i] == left.top()) { left.pop(); continue; }
        if (left.empty()) res.push_back(i);
      }
    }
    sort(res.begin(), res.end());
    for (int& num : res) num = asteroids[num];
    return res;
  }
};


// more concise
class Solution_1 {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      vector<int> res;
      for (int i = 0; i < (int)asteroids.size(); ++i) {
        if (asteroids[i] >= 0) res.push_back(asteroids[i]);
        else if (res.empty() || res.back() < 0) res.push_back(asteroids[i]);
        else if (-asteroids[i] >= res.back()) {
          if (-asteroids[i] > res.back()) --i;
          res.pop_back();
        }
      }
      return res;
    }
};


int main() {
  Solution s;
  vector<int> a = {1,10,-10,-1,-2};
  auto r = s.asteroidCollision(a);
  for (auto& e : r) cout << e << " "; cout << endl; 
  return 0;
}
