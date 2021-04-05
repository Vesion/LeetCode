#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// A rectange's two diagonals are intersected in the middle point with same length.
// Firstly find all segments in O(N^2) and store them with the middle point as the key,
// then for every pair of segments, check if they are of the same length (can be two diagonals
// of a rectangle), if so calculate its area.
class Solution {
public:
    size_t d2(int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
    double minAreaFreeRect(vector<vector<int>>& ps, size_t res = 0) {
      unordered_map<size_t, vector<vector<int>>> m;
      for (auto i = 0; i < ps.size(); ++i)
        for (auto j = i + 1; j < ps.size(); ++j) {
          auto center = ((size_t)(ps[i][0] + ps[j][0]) << 16) + ps[i][1] + ps[j][1];
          m[center].push_back({ ps[i][0], ps[i][1], ps[j][0], ps[j][1] });
        }
      for (auto it = begin(m); it != end(m); ++it)
        for (auto i = 0; i < it->second.size(); ++i)
          for (auto j = i + 1; j < it->second.size(); ++j) {
            auto &p1 = it->second[i], &p2 = it->second[j];
            if ((p1[0] - p2[0]) * (p1[0] - p2[2]) + (p1[1] - p2[1]) * (p1[1] - p2[3]) == 0) {
              auto area = d2(p1[0], p1[1], p2[0], p2[1]) * d2(p1[0], p1[1], p2[2], p2[3]);
              if (res == 0 || res > area) res = area;
            }
          }
      return sqrt(res);
    }
};

int main() {

}