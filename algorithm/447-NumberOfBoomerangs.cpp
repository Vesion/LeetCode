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
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            m.clear();
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int d = (points[i].first-points[j].first)*(points[i].first-points[j].first) + (points[i].second-points[j].second)*(points[i].second-points[j].second);
                m[d]++;
            }
            for (auto& p : m) if (p.second >= 2) res += p.second * (p.second-1);
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

