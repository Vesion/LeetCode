#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <set> 
#include <queue> 
using namespace std;

// Solution 1 : Compare areas and use sweep line to detect overlapping, O(nlogn)
// Very skillful to use std::set, rather than verbose interval/segment tree!
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left = INT_MAX, bottom = INT_MAX, right = INT_MIN, top = INT_MIN;
        int area = 0;

        // {time, index}
        // time is the x-coordinate of each vertical edge, 
        // index is each edge's id, furthermore, it indicates it's a left edge or right edge, left for inserting, right for removing, and we use negative index for right edge
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (int i = 0; i < (int)rectangles.size(); ++i) {
            int x1 = rectangles[i][0], y1 = rectangles[i][1], x2 = rectangles[i][2], y2 = rectangles[i][3];
            left = min(left, x1), bottom = min(bottom, y1);
            right = max(right, x2), top = max(top, y2);

            area += (x2-x1)*(y2-y1);

            pq.push({x1, i+1});
            pq.push({x2, -(i+1)});
        }
        if (area != (right-left)*(top-bottom)) return false;
        
        // we detect vertical edges overlapping when they are inserted into a interval tree (here we use std::set)
        // if two vertical edges occur like below:
        //          |
        //          |
        //      |   |
        //      |   e2
        //      |
        //      e1
        // they overlap, in this case we do not allow to insert successfully
        auto cmp = [&rectangles](const int& i, const int& j) {
            if (rectangles[i][1] < rectangles[j][3] && rectangles[i][3] > rectangles[j][1]) return false;
            return rectangles[i][1] < rectangles[j][1];
        };
        set<int, decltype(cmp)> s(cmp);
        while (!pq.empty()) {
            int i = pq.top().second; pq.pop();
            if (i > 0) {
                if (s.count(i-1)) return false;
                s.insert(i-1);
            } else s.erase(-i-1);
        }
        return true;
    }
};


// Solution 2 : Compare areas and count points, O(n)
// Perfect rectangle must satisfy two conditions:
//      1. the large rectangle area should be equal to the sum of small rectangles
//      2. there must be even number of inner points, and must be only one point for four corners
class Solution_2 {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.empty()) return false;

        int x1 = INT_MAX, y1 = INT_MAX;
        int x2 = INT_MIN, y2 = INT_MIN;
        unordered_set<string> s;
        int area = 0;

        for (auto& rect : rectangles) {
            x1 = min(x1, rect[0]), y1 = min(y1, rect[1]);
            x2 = max(x2, rect[2]), y2 = max(y2, rect[3]);

            area += (rect[0]-rect[2]) * (rect[1]-rect[3]);

            string point1 = to_string(rect[0]) + " " + to_string(rect[1]);
            string point2 = to_string(rect[0]) + " " + to_string(rect[3]);
            string point3 = to_string(rect[2]) + " " + to_string(rect[1]);
            string point4 = to_string(rect[2]) + " " + to_string(rect[3]);
            if (s.count(point1)) s.erase(point1); else s.insert(point1);
            if (s.count(point2)) s.erase(point2); else s.insert(point2);
            if (s.count(point3)) s.erase(point3); else s.insert(point3);
            if (s.count(point4)) s.erase(point4); else s.insert(point4);
        }

        if (s.size() != 4 
            || !s.count(to_string(x1) + " " + to_string(y1)) 
            || !s.count(to_string(x1) + " " + to_string(y2)) 
            || !s.count(to_string(x2) + " " + to_string(y1)) 
            || !s.count(to_string(x2) + " " + to_string(y2))) 
            return false;
        return area == (x1-x2) * (y1-y2);
    }
};


int main() {
    return 0;
}

