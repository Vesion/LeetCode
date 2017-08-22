#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
#include <unordered_set> 
using namespace std;

// Solution 1 : sort left half and right half, then check pairwise
class Solution_1 {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty()) return true;
        int minx = INT_MAX, maxx = INT_MIN;
        for (auto& p : points) minx = min(minx, p.first), maxx = max(maxx, p.first);
        double midx = (minx + maxx) * 0.5;

        // use std::set to remove duplicates and sort
        auto cmp = [](const pair<int,int>& p1, const pair<int,int>& p2) {
            if (p1.first == p2.first) return p1.second > p2.second;
            return p1.first < p2.first;
        };
        set<pair<int,int>, decltype(cmp)> left(cmp);
        set<pair<int,int>> right;
        for (auto& p : points) {
            if (p.first < midx) left.insert(p);
            else if (p.first > midx) right.insert(p);
        }

        if (left.size() != right.size()) return false;
        auto li = left.begin();
        auto ri = right.rbegin();
        while (li != left.end()) {
            if ((li->first+ri->first)*0.5 == midx && li->second == ri->second) ++li, ++ri;
            else return false;
        }
        return true;
    }
};


// Solution 2 : using string hash trick
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int minx = INT_MAX, maxx = INT_MIN;
        unordered_set<string> s;
        for (auto& p : points) {
            minx = min(minx, p.first);
            maxx = max(maxx, p.first);
            s.insert(to_string(p.first) + " " + to_string(p.second));
        }
        int sum = minx + maxx;
        for (auto& p : points) {
            if (!s.count(to_string(sum-p.first) + " " + to_string(p.second))) return false;
        }
        return true;
    }
};


int main() {
    return 0;
}

