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
    static constexpr int kMin = numeric_limits<int>::lowest();
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int res = kMin;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < points.size(); ++i) {
            while (!pq.empty() && points[i][0]-pq.top().second > k) pq.pop();
            if (!pq.empty()) {
                res = max(res, points[i][1]+points[i][0]+pq.top().first);
            }
            pq.push({points[i][1]-points[i][0], points[i][0]});
        }
        return res;
    }
};

// monotonic queue, O(n)
class Solution {
public:
    static constexpr int kMin = numeric_limits<int>::lowest();

    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // monotonically decreasing queue
        deque<pair<int,int>> q;
        int res = kMin;
        for (const auto& p : points) {
            while (!q.empty() && p[0]-q.front().second > k) q.pop_front();
            if (!q.empty()) res = max(res, p[0]+p[1]+q.front().first);
            while (!q.empty() && q.back().first <= p[1]-p[0]) q.pop_back();
            q.push_back({p[1]-p[0], p[0]});
        }
        return res;
    }
};

int main() {
}
