#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Heap, O(KlogK), K = M*N
class Solution0 {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        using S = tuple<int,int,int>;
        priority_queue<S, vector<S>, greater<S>> pq;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            int d = abs(workers[i][0] - bikes[j][0]) +
                    abs(workers[i][1] - bikes[j][1]);
            pq.push({d, i, j});
        }
        vector<bool> b(m, false);
        vector<int> res(n, -1);
        while (!pq.empty()) {
            auto [d, i, j] = pq.top(); pq.pop();
            if (res[i] != -1 || b[j]) continue;
            res[i] = j;
            b[j] = true;
        }
        return res;
    }
};

// Can replace heap with bucket sort, reduce to O(M*N)
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        constexpr int kMax = 2005;
        vector<vector<pair<int,int>>> bucket(kMax);
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
            int d = abs(workers[i][0] - bikes[j][0]) +
                    abs(workers[i][1] - bikes[j][1]);
            bucket[d].push_back({i, j});
        }
        vector<bool> b(m, false);
        vector<int> res(n, -1);
        for (int d = 0; d < kMax; ++d) {
            for (const auto& p : bucket[d]) {
                int i = p.first, j = p.second;
                if (res[i] != -1 || b[j]) continue;
                res[i] = j;
                b[j] = true;
            }
        }
        return res;
    }
};

int main() {

}
