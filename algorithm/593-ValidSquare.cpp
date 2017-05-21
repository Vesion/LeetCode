#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        set<vector<int>> s;
        s.insert(p1); s.insert(p2); s.insert(p3); s.insert(p4);
        if (s.size() != 4) return false;
        vector<vector<int>> vs(s.begin(), s.end());
        vector<int> v1 = {vs[0][0]-vs[1][0], vs[0][1]-vs[1][1]},
                    v2 = {vs[0][0]-vs[2][0], vs[0][1]-vs[2][1]},
                    v3 = {vs[0][0]-vs[3][0], vs[0][1]-vs[3][1]},
                    v4 = {vs[1][0]-vs[2][0], vs[1][1]-vs[2][1]};
        return vertical(v1, v2) && vertical(v3, v4);
    }

    bool vertical(vector<int>& v1, vector<int>& v2) {
        return v1[0]*v2[0]+v1[1]*v2[1] == 0;
    }
};

int main() {
    return 0;
}
