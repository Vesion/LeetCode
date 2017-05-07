#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        height = width = 0; // useless parameters
        int res = 0;
        int maxdiff = INT_MIN;
        for (auto& nut : nuts) {
            int sn = abs(squirrel[0]-nut[0]) + abs(squirrel[1]-nut[1]);
            int tn = abs(tree[0]-nut[0]) + abs(tree[1]-nut[1]);
            int diff = tn-sn;
            if (diff > maxdiff) maxdiff = diff;
            res += 2*tn;
        }
        res -= maxdiff;
        return res;
    }
};


int main() {
    return 0;
}
