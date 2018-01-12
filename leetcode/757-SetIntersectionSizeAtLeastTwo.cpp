#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// intervals, greedy
// https://discuss.leetcode.com/topic/115540/java-o-nlogn-solution-greedy
//
class Solution {
public:
  int intersectionSizeTwo(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& i1, const vector<int>& i2) { // sort with end points
      return i1[1] < i2[1] || (i1[1] == i2[1] && i1[0] > i2[0]);
    });
    int res = 0, p1 = -1, p2 = -1;
    for (auto& i : intervals) {
      if (i[0] <= p1) continue; // two numbers in the interval
      if (i[0] > p2) { // no number in the interval, pick up two new largest numbers from the interval
        res += 2;
        p2 = i[1];
        p1 = i[1]-1;
      } else { // one number in the interval, pick up the largest number from the interval
        ++res;
        p1 = p2;
        p2 = i[1];
      }
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<vector<int>> i = { { 1,3 },{ 4,9 },{ 0,10 },{ 6,7 },{ 1,2 },{ 0,6 },{ 7,9 },{ 0,1 },{ 2,5 },{ 6,8 } }; // 7
  cout << s.intersectionSizeTwo(i) << endl; // 7
  return 0;
}
