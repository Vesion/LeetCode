#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : O(n^2), based on 729-MyCalendarI, check overlap if overlapped with overlaps before
class MyCalendar {
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

class MyCalendarTwo {
private:
  vector<pair<int,int>> books;

public:
  bool book(int start, int end) {
    MyCalendar overlaps;
    for (auto& p : books) {
      if (max(start, p.first) < min(end, p.second)) {
        if (!overlaps.book(max(start, p.first), min(end, p.second))) return false;
      }
    }
    books.push_back({start, end});
    return true;
  }
};


// Solution 2 : BST, similar to 715-RangeModule


int main() {
  MyCalendarTwo m;
  cout << m.book(1,2) << endl;
  cout << m.book(1,2) << endl;
  cout << m.book(1,2) << endl;
  return 0;
}
