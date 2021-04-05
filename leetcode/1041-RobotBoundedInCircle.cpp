#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


// complete instructions at most 4 times
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, d = 0;
        constexpr int go[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for (int i = 0; i < 4; ++i) {
            for (char c : instructions) {
                if (c == 'G') {
                    x += go[d][0];
                    y += go[d][1];
                }
                else if (c == 'L') d = (d+4-1)%4;
                else d = (d+1)%4;
            }
            if (x == 0 && y == 0 && d == 0) return true;
        }
        return false;
    }
};


// Only 1 time
// https://leetcode.com/problems/robot-bounded-in-circle/discuss/290856/JavaC%2B%2BPython-Let-Chopper-Help-Explain
class Solution1 {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
        for (char & ins : instructions)
            if (ins == 'R')
                i = (i + 1) % 4;
            else if (ins == 'L')
                i = (i + 3) % 4;
            else
                x += d[i][0], y += d[i][1];
        return x == 0 && y == 0 || i > 0;
    }
};

int main() {

}