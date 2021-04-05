#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

// O(n)
class MyCalendar0 {
private:
  vector<pair<int,int>> books;

public:
  bool book(int start, int end) {
    for (auto& p : books) {
      if (max(start, p.first) < min(end, p.second)) return false;
    }
    books.push_back({start, end});
    return true;
  }
};


// BST, O(logn)
class MyCalendar {
public:
    map<int,int> m;

    MyCalendar() {}

    bool book(int start, int end) {
        auto it = m.upper_bound(start);
        if (it != m.begin() && prev(it)->second > start) return false;
        if (it != m.end() && it->first < end) return false;
        m[start] = end;
        return true;
    }
};


int main() {
  return 0;
}
