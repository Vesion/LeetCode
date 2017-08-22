#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <unordered_map> 
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> m;
            for (int j = 0; j < n; ++j) {
                int x0 = points[i].first, y0 = points[i].second;
                int x1 = points[j].first, y1 = points[j].second;
                int d = (x0-x1)*(x0-x1) + (y0-y1)*(y0-y1);
                m[d]++;
            }
            for (auto& p : m) res += p.second * (p.second-1);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<pair<int,int>> p = {{0,0}, {1,0}, {2,0}};
    cout <<s.numberOfBoomerangs(p) << endl;
    return 0;
}
