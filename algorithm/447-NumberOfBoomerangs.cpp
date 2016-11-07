#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;
        unordered_map<long long, int> g;
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    g[dist(points[i], points[j])]++;
                }
            }
            for (auto& p : g)
                res += (p.second * (p.second-1));
            g.clear();
        }
        return res;
    }

    long long dist(pair<int,int>&p1, pair<int,int>&p2) {
        long long r = (p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second);
        return r;
    }
};

int main() {
    Solution solution;
    vector<pair<int, int>> points = {{0,0}, {0,1}, {0,-1}, {10000, 0}};
    cout << solution.numberOfBoomerangs(points) << endl;
    return 0;
}

