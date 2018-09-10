#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
#include <queue> 
using namespace std;

// Version 1 :  Given two rectilinear rectangles, judge whether they have overlapped area.
struct Rectangle {
    int x1, y1; // left bottom
    int x2, y2; // right top
};

// Just check if r1 is totally left/right/bottom/top of r2.
bool overlapped(Rectangle& r1, Rectangle& r2) {
    return !(r1.x2 <= r2.x1 || r2.x2 <= r1.x1 || r1.y2 <= r2.y1 || r2.y2 <= r1.y1);
}


// Version 2 : Detect if there any two rectangles overlapped in a 2D plane
// https://leetcode.com/problems/perfect-rectangle/
//
// Solution : Sweep line
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if (rectangles.empty()) return false;

        // {time, index}
        // time is the x-coordinate of each vertical edge, 
        // index is each edge's id, furthermore, it indicates it's a left edge or right edge, left for inserting, right for removing, and we use negative index for right edge
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> events;
        
        for (int i = 0; i < (int)rectangles.size(); ++i) {
            auto& rect = rectangles[i];
            events.push({rect[0], i+1});
            events.push({rect[2], -(i+1)});
        }

        // we detect vertical edges overlapping when they are inserted into a interval tree (here we use std::set)
        // if two vertical edges occur like below:
        //          |
        //          |
        //      |   |
        //      |   e2
        //      |
        //      e1
        // they overlap, in this case we do not allow to insert successfully
        auto comp = [&rectangles] (int i, int j) {
            if (rectangles[i][1] < rectangles[j][3] && rectangles[j][1] < rectangles[i][3]) return false;
            return rectangles[i][1] < rectangles[j][1];
        };
        set<int, decltype(comp)> verticals(comp);

        while (!events.empty()) {
            auto e = events.top(); events.pop();
            if (e.second > 0) { // this is a left edge, try to insert it
                if (verticals.count(e.second-1)) // if find overlapping, return false
                    return false;
                verticals.insert(e.second-1);
            } else { // this is a right edge, remove it
                verticals.erase(-e.second-1);
            }
        }
        return true;
    }
};


int main() {
    return 0;
}
