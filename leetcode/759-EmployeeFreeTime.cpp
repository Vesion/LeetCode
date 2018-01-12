#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
    vector<Interval> t;
    for (auto& e : schedule) for (auto& i : e) t.push_back(i);
    sort(t.begin(), t.end(), [](const Interval& i1, const Interval& i2) {
      return i1.start < i2.start || (i1.start == i2.start && i1.end < i2.end);
    });
    vector<Interval> r;
    for (auto& i : t) {
      if (r.empty() || i.start > r.back().end) r.push_back(i);
      else r.back().end = max(r.back().end, i.end);
    }
    vector<Interval> res;
    for (int i = 1; i < (int)r.size(); ++i) res.push_back({r[i-1].end, r[i].start});
    return res;
  }
};


int main() {
  Solution s;
  vector<vector<Interval>> sc = { { { 1,3 },{ 6,7 } },{ { 2,4 } },{ { 2,5 },{ 9,12 } } };
  auto r = s.employeeFreeTime(sc);
  for (auto& e : r) cout << e.start << " " << e.end << endl;
  return 0;
}
