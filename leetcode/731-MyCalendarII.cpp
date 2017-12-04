#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
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


// Solution 2 : O(n), go through all points one by one in sorting order
class MyCalendarTwo_2 {
private:
  map<int,int> m;

public:
  bool book(int start, int end) {
    int cur = 0;
    ++m[start];
    --m[end];
    for (auto& p : m) {
      cur += p.second;
      if (cur >= 3) {
        --m[start];
        ++m[end];
        return false;
      }
    }
    return true;
  }
};


// Solution 3 : BST, O(logn), similar to 715-RangeModule


int main() {
  MyCalendarTwo m;
  cout << m.book(1,2) << endl;
  cout << m.book(1,2) << endl;
  cout << m.book(1,2) << endl;
  return 0;
}
