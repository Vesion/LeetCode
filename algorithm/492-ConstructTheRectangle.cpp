#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width = sqrt(area);
        while (area % width) --width;
        return {area/width, width};
    }
};


int main() {
    return 0;
}
