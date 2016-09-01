#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

// Judging if there are any two rectanges overlapped, is a very classical problem.
// Solution : Swipe line

class Solution {
public:
    using ll = long long;
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.empty()) return false;
        int minX = rectangles[0][0], minY = rectangles[0][1];
        int maxX = rectangles[0][2], maxY = rectangles[0][3];
        vector<pair<int, int>> events;

        ll actualArea = 0;
        for (int i = 0; i < (int)rectangles.size(); ++i) {
            int x1 = rectangles[i][0], y1 = rectangles[i][1], x2 = rectangles[i][2], y2 = rectangles[i][3];
            minX = min(minX, x1), minY = min(minY, y1);
            maxX = max(maxX, x2), maxY = max(maxY, y2);
            actualArea += (ll)(x2-x1) * (y2-y1);
            events.push_back({x1, i+1});
            events.push_back({x2, -(i+1)});
        }

        ll idealArea = (ll)(maxX-minX)*(maxY-minY);
        if (idealArea != actualArea) return false;

        sort(events.begin(), events.end());

        auto cmp = [&] (int i, int j) { // the core thoughts !
            if (rectangles[i][1] < rectangles[j][3] && rectangles[j][1] < rectangles[i][3])
                return false;
            return rectangles[i][1] < rectangles[j][1];
        };

        set<int, decltype(cmp)> verticals(cmp);

        for (auto &e : events) {
            if (e.second > 0) {
                if (verticals.count(e.second-1)) return false;
                verticals.insert(e.second-1);
            } else
                verticals.erase(-e.second-1);
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> rectangles = {
          { 1,1,3,3 },
  { 1,3,2,4 },
  { 2,2,4,4 }

    };
    cout << s.isRectangleCover(rectangles) <<endl;
    return 0;
}

