#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// heap, O(nlogk)
class Solution1 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<int> dist(n);
        for (int i = 0; i < n; ++i) {
            const vector<int>& p = points[i];
            dist[i] = p[0]*p[0] + p[1]*p[1];
        }
        auto cmp = [&dist](int i, int j) {
            return dist[i] < dist[j];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; ++i) {
            pq.push(i);
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(points[pq.top()]);
            pq.pop();
        }
        return res;
    }
};


// quickselect, O(n)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& A, int K) {
        nth_element(A.begin(), A.begin() + K, A.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return vector<vector<int>>(A.begin(), A.begin() + K);
    }
};

int main() {

}