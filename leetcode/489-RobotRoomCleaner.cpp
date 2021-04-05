#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    const int go[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    int x = 0, y = 0, d = 0;
    set<pair<int,int>> s;

    void cleanRoom(Robot& r) {
        r.clean();
        s.insert({x, y});
        for (int i = 0; i < 4; ++i) {
            if (!s.count({x+go[d][0], y+go[d][1]}) && move(r)) {
                cleanRoom(r);
                turn_left(r); turn_left(r);
                move(r);
                turn_left(r); turn_left(r);
            }
            turn_left(r);
        }
    }

    bool move(Robot& r) {
        if (r.move()) {
            x += go[d][0], y += go[d][1];
            return true;
        }
        return false;
    }

    void turn_left(Robot& r) {
        r.turnLeft();
        d = (d+1)%4;
    }
};

int main() {
    return 0;
}
