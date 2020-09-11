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
    int x = 0, y = 0;
    int go[2] = {0, 1};

    void lr(Robot& robot) {
        robot.turnLeft();
        int ny = -go[1];
        go[1] = go[0];
        go[0] = ny;
    }

    bool move(Robot& robot) {
        if (robot.move()) {
            x += go[0], y += go[1];
            return true;
        }
        return false;
    }

    set<pair<int,int>> v;

    void cleanRoom(Robot& robot) {
        int d = 0;
        robot.clean();
        v.insert({x, y});
        while (d < 4) {
            if (!v.count({x+go[0], y+go[1]}) && move(robot)) {
                cleanRoom(robot);
                lr(robot); lr(robot);
                move(robot);
                lr(robot); lr(robot);
            }
            lr(robot);
            ++d;
        }
    }
};

int main() {
    return 0;
}
