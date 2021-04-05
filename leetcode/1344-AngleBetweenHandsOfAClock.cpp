#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ma = 360.0 * (minutes / 60.0);
        double ha = 360.0 * (hour / 12.0) + 30.0 * (minutes / 60.0);
        double diff = abs(ma-ha);
        return min(diff, 360.0 - diff);
    }
};

int main() {
}
