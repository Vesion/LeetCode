#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

// BST, O(logn)
class MyCalendar {
public:
    map<int,int> m;

    MyCalendar() {
    }

    bool book(int start, int end) {
        assert(start < end);
        auto it = m.lower_bound(start);
        if ((it != m.end() && it->first < end) ||
            (it != m.begin() && (--it)->second > start)) {
            return false;
        }
        m[start] = end;
        return true;
    }
};


int main() {
  return 0;
}
