#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// https://leetcode.com/problems/swap-adjacent-in-lr-string/discuss/217070/Python-using-corresponding-position-
class Solution {
public:
    bool canTransform(string start, string end) {
        int m = start.size(), n = end.size();
        if (m != n) return false;
        vector<pair<char,int>> a, b;
        for (int i = 0; i < n; ++i) {
            if (start[i] == 'L' || start[i] == 'R')
                a.emplace_back(start[i], i);
            if (end[i] == 'L' || end[i] == 'R')
                b.emplace_back(end[i], i);
        }
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i].first != b[i].first) return false;
            if (a[i].first == 'L' && a[i].second < b[i].second) return false;
            if (a[i].first == 'R' && a[i].second > b[i].second) return false;
        }
        return true;
    }
};


int main() {
  Solution s;
  cout << s.canTransform("XRLXLXXXLXRXXXLXLLXX", "XRXXLXXLXLRXXLXXLXXL") << endl;
  return 0;
}
