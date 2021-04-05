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
        vector<vector<int>> v(s.begin(), s.end());
        vector<int> v1 = {{v[0][0]-v[1][0], v[0][1]-v[1][1]}};
        vector<int> v2 = {{v[0][0]-v[2][0], v[0][1]-v[2][1]}};
        vector<int> v3 = {{v[0][0]-v[3][0], v[0][1]-v[3][1]}};
        vector<int> v4 = {{v[1][0]-v[2][0], v[1][1]-v[2][1]}};
        return inner_prod(v1, v2) == 0 && inner_prod(v3, v4) == 0
            && length2(v3) == length2(v4);
    }

    int inner_prod(const vector<int>& v1, const vector<int>& v2) {
        return v1[0]*v2[0] + v1[1]*v2[1];
    }

    int length2(const vector<int>& v) {
        return v[0]*v[0] + v[1]*v[1];
    }
};

int main() {
    return 0;
}


