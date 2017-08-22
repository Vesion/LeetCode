#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> lines;
        for (auto& row : wall) {
            int width = 0;
            for (int i = 0; i < (int)row.size()-1; ++i) ++lines[width+=row[i]];
        }
        int res = wall.size();
        for (auto& line : lines) res = min(res, (int)wall.size()-line.second);
        return res;
    }
};


int main() {
    return 0;
}
