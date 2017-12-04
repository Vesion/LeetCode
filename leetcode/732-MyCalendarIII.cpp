#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
using namespace std;


// Solution 1 : O(n)
class MyCalendarThree {
private:
  map<int,int> m;

public:
  MyCalendarThree() { }
  
  int book(int start, int end) { // O(n)
    ++m[start];
    --m[end];
    int res = 0, cur = 0;
    for (auto& p : m) res = max(res, cur += p.second);
    return res;
  }
};


// Solution 2 : O(logN), N is the data range, 10^9 here


int main() {
  MyCalendarThree m;
  return 0;
}
