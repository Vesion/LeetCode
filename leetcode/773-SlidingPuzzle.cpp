#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
#include <unordered_map> 
using namespace std;

// Solution 1 : bitmap, calculate move direction
class Solution {
public:
  int slidingPuzzle(vector<vector<int>>& board) {
    int target = 0b001010011100101000; // 123450
    int total = 0b101100011010001000; // 543210
    vector<int> m(total+1, 0);
    int s = 0, sp = 0, i = 0;
    for (auto& row : board) for (int& d : row) {
      if (d == 0) sp = i;
      s = (s<<3)|d;
      ++i;
    }
    queue<pair<int,int>> q;
    q.push({s, sp}); m[s] = 1;
    int step = 0;
    while (!q.empty()) {
      int len = q.size();
      while (len--) {
        auto t = q.front(); q.pop();
        int c = t.first, p = t.second;
        if (c == target) return step;
        for (int inc = -3; inc <= 3; inc += 2) {
          int np = p + inc;
          if (np < 0 || np > 5 || (p == 2 && inc == 1) || (p == 3 && inc == -1)) continue;
          int nc = c;
          nc &= ~(0b111 << (3*(5-np)));
          nc |= (((c>>(3*(5-np))) & 0b111) << (3*(5-p)));
          if (m[nc]) continue;
          q.push({nc, np}); m[nc] = 1;
        }
      }
      ++step;
    }
    return -1;
  }
};


// Solution 2 : string, move direction constant
class Solution_2 {
public:
  unordered_map<int, vector<int>> moves{{0,{1,3}},{1,{0,2,4}},{2,{1,5}},{3,{0,4}},{4,{3,5,1}},{5,{4,2}}}; // move direction
  int slidingPuzzle(vector<vector<int>>& b) {
    string s;
    for (auto& row : b) for (int& d : row) s += to_string(d);
    unordered_map<string, int> m({{s, 0}});
    queue<pair<string, int>> q({{s, s.find('0')}});

    for (;!q.empty() && q.front().first != "123450";q.pop()) {
      for (auto new_zero : moves[q.front().second]) {
        string cur = q.front().first;
        swap(cur[q.front().second], cur[new_zero]);
        if (m.insert({cur, m[q.front().first] + 1}).second) q.push({cur, new_zero});
      }   
    }
    return q.empty() ? -1 : m[q.front().first];
  }
};


int main() {
  Solution s;
  vector<vector<int>> b = {
    {3,2,4},
    {1,5,0}
  };
  cout << s.slidingPuzzle(b) << endl;
  return 0;
}
