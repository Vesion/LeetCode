#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

// Solution 1 : without set or map, verbose, O(nlogn)
class Solution_1 {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty()) return true;
        int n = points.size();
        sort(points.begin(), points.end()); // sort with x
        sort(points.begin(), points.begin()+(n+1)/2,
                [] (const pair<int,int>& p1, const pair<int,int>& p2) { // sort first half with smaller x and larger y
                    if (p1.first != p2.first) return p1.first < p2.first;
                    return p1.second > p2.second;
                });

        float midx = (points[0].first + points[n-1].first) * 0.5;
        if (midx == points[0].first) return true; // all points are in same line
        if (points[0].second != points[n-1].second) return false; // judge first and last point

        int i = 1, j = n-2;
        while (i <= j) {
            if (points[i] == points[i-1]) { ++i; continue; } // skip coincide points
            if (points[j] == points[j+1]) { --j; continue; }

            float x = (points[i].first + points[j].first) * 0.5;
            if (x != midx) return false;
            if (points[i].second != points[j].second && x != midx) return false; // if y's different, need to double check x in case in the mid line
            ++i, --j;
        }
        return true;
    }
};


// Solution 2 : set, use string trick to hash, much more concise
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int left = INT_MAX, right = INT_MIN;
        set<string> s;
        for (auto& p : points) {
            left = min(left, p.first);
            right = max(right, p.first);
            s.insert(to_string(p.first) + " " + to_string(p.second));
        }

        int sum = left + right;
        for (auto& p : points) {
            string ps = to_string(sum-p.first) + " " + to_string(p.second);
            if (!s.count(ps)) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<pair<int,int>> p = {{1,1},{0,1},{-1,1},{0,0}};
    cout << s.isReflected(p) << endl;
    return 0;
}
