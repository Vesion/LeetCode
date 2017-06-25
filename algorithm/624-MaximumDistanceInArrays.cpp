#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minx = arrays[0].front(), maxx = arrays[0].back();
        int res = 0;
        for (int i = 1; i < (int)arrays.size(); ++i) {
            res = max(res, abs(arrays[i].front()-maxx));
            res = max(res, abs(arrays[i].back()-minx));
            minx = min(minx, arrays[i].front());
            maxx = max(maxx, arrays[i].back());
        }
        return res;
    }
};


int main() {
    return 0;
}
