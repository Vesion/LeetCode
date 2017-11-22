#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
using namespace std;

// Solution 1 : vector, O(n)
class MyCalendar_1 {
private:
  vector<pair<int,int>> m;
public:
    bool book(int start, int end) {
      for (auto& p : m) {
        if (max(start, p.first) < min(end, p.second)) return false;
      }
      m.push_back({start, end});
      return true;
    }
};


// Solution 2 : BST, O(logn)
class MyCalendar {
private:
  map<int,int> m;
public:
    bool book(int start, int end) {
      auto it = m.lower_bound(start);
      if ((it != m.end() && end > it->first) || (it != m.begin() && start < (--it)->second)) return false;
      m[start] = end;
      return true;
    }
};


int main() {
  return 0;
}
