#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// hash table
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> m;
        for (const auto& p : points) {
            m[p[0]].insert(p[1]);
        }
        int res = INT_MAX;
        for (int i = 0; i < points.size(); ++i) {
            const auto& pi = points[i];
            for (int j = i+1; j < points.size(); ++j) {
                const auto& pj = points[j];
                // try to find two end points of the diagonal of a rectangle
                if (pi[0] == pj[0] || pi[1] == pj[1]) continue;
                if (m[pi[0]].count(pj[1]) && m[pj[0]].count(pi[1])) {
                    res = min(res, abs(pi[0]-pj[0]) * abs(pi[1]-pj[1]));
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};


// sort and hash table, much faster after doing some optimization
class Solution2 {
public:
    struct Hash {
        size_t operator()(const pair<int,int>&x)const{
            return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
        }
    };

    pair<int,int> count(vector<vector<int>>& points) {
        unordered_set<int> xs, ys;
        for (auto& p : points) {
            xs.insert(p[0]);
            ys.insert(p[1]);
        }
        return {xs.size(), ys.size()};
    }

    int minAreaRect(vector<vector<int>>& points) {
        // optimization-1: check if all points are in the same line
        const auto&[nx, ny] = count(points);
        if (nx == 0 || ny == 0) return 0;

        // optimization-2: reverse x and y according to count
        map<int, vector<int>> x2y;
        if (nx > ny)
            for (auto& p : points)
                x2y[p[0]].emplace_back(p[1]);
        else
            for (auto& p : points)
                x2y[p[1]].emplace_back(p[0]);

        unordered_map<pair<int,int>, int, Hash> seenPairsOfY2X;
        int res = numeric_limits<int>::max();
        for (auto&[x, ys] : x2y) {
            sort(ys.begin(), ys.end());
            for (int i = 0; i < ys.size(); ++i)
                for (int j = 0; j < i; ++j) {
                    int y1 = ys[j], y2 = ys[i]; // y2 > y1
                    if (seenPairsOfY2X.count({y1,y2})) {
                        int x1 = seenPairsOfY2X[{y1,y2}];
                        int x2 = x;
                        int area = (y2 - y1) * (x2 - x1);
                        res = min(res, area);
                    }
                    seenPairsOfY2X[{y1,y2}] = x;
                }
        }
        return res == numeric_limits<int>::max() ? 0 : res;
    }
};


int main() {
}
