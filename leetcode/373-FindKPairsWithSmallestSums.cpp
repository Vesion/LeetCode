#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// similar to 378-KthSmallestElementInASortedMatrix
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        using S = pair<int,int>;
        auto cmp = [&nums1, &nums2](const S& a, const S& b) {
            return nums1[a.first] + nums2[a.second] >
                   nums1[b.first] + nums2[b.second];
        };
        priority_queue<S, vector<S>, decltype(cmp)> pq(cmp);
        vector<vector<int>> res;
        pq.push({0, 0});
        while (k-- && !pq.empty()) {
            auto [i, j] = pq.top(); pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j+1 < n2) pq.push({i, j+1});
            if (j == 0 && i+1 < n1) pq.push({i+1, j});
        }
        return res;
    }
};


int main() {
    return 0;
}
