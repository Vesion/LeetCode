#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

// map, O(nlogn)
class Solution0 {
public:
    static constexpr int kMin = numeric_limits<int>::lowest();
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int res = kMin;
        map<int,int> m;
        for (int i = 0, j = 0; j < points.size(); ++j) {
            while (points[j][0] - points[i][0] > k && i < j && !m.empty()) {
                if (--m[points[i][1]-points[i][0]] == 0) {
                    m.erase(points[i][1]-points[i][0]);
                }
                ++i;
            }
            if (!m.empty()) {
                res = max(res, points[j][1]+points[j][0]+m.rbegin()->first);
            }
            m[points[j][1]-points[j][0]]++;
        }
        return res;
    }
};

// max-heap, O(nlogn)
class Solution1 {
public:
    // max((yj+xj) + (yi-xi))
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int s = numeric_limits<int>::lowest();
        priority_queue<pair<int,int>> pq;
        for (const auto& p : points) {
            int xi = p[0], yi = p[1];
            while (!pq.empty() && xi - pq.top().second > k) pq.pop();
            if (!pq.empty()) s = max(s, xi + yi + pq.top().first);
            pq.push({yi-xi, xi});
        }
        return s;
    }
};

// monotonically decreasing deque
// similar to 239-SlidingWindowMaximum
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int,int>> q;
        int res = INT_MIN;
        for (const auto& p : points) {
            int xi = p[0], yi = p[1];
            while (!q.empty() && xi - q.front().second > k) q.pop_front();
            if (!q.empty()) res = max(res, yi+xi+q.front().first);
            while (!q.empty() && yi-xi > q.back().first) q.pop_back();
            q.push_back({yi-xi, xi});
        }
        return res;
    }
};

int main() {
}
