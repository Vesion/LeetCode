#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
using namespace std;

// https://discuss.leetcode.com/topic/107974/c-vector-o-n-and-map-o-logn-compare-two-solutions

// Solution 1 : vector, O(n) add and delete, O(logn) query


// Solution 2 : BST, O(klogn) add and delete (k is the number of overlapping ranges), O(logn) query
class RangeModule {
private:
  map<int, int> intervals;

public:
  RangeModule() { }
  
  void addRange(int left, int right) {
    auto l = intervals.upper_bound(left), r = intervals.upper_bound(right);
    if (l != intervals.begin()) {
      --l;
      if (l->second < left) ++l;
    }
    if (l != r) {
      left = min(left, l->first);
      right = max(right, (--r)->second);
      intervals.erase(l, ++r); // O(klogn)
    }
    intervals[left] = right;
  }
  
  bool queryRange(int left, int right) {
    auto it = intervals.upper_bound(left);
    return it != intervals.begin() && (--it)->second >= right;
  }
  
  void removeRange(int left, int right) {
    auto l = intervals.upper_bound(left), r = intervals.upper_bound(right); 
    if (l != intervals.begin()) {
      --l;
      if (l->second < left) ++l;
    }
    if (l == r) return;
    int l1 = min(left, l->first), r1 = max(right, (--r)->second);
    intervals.erase(l, ++r); // O(klogn)
    if (l1 < left) intervals[l1] = left;
    if (r1 > right) intervals[right] = r1;    
  }
};


// Solution 3 : Segment Tree, O(logn) add and delete, O(logn) query, but here numbers are in (0, 10^9)


int main() {
  return 0;
}
