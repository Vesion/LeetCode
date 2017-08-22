#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// similar to 378-KthSmallestElementInASortedMatrix
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty()) return {};
        int n1 = nums1.size(), n2 = nums2.size();
        auto cmp = [&nums1, &nums2](const pair<int,int>& p1, const pair<int,int>& p2) {
            return nums1[p1.first]+nums2[p1.second] > nums1[p2.first]+nums2[p2.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp); // a min-heap
        vector<pair<int,int>> res;
        pq.push({0, 0});
        while (k-- && !pq.empty()) {
            auto t = pq.top(); pq.pop();
            res.push_back({nums1[t.first], nums2[t.second]});
            if (t.second+1 < n2) pq.push({t.first, t.second+1}); // extend rightward
            if (t.second == 0 && t.first+1 < n1) pq.push({t.first+1, t.second}); // if this is the first one in a row, extend downward
        }
        return res;
    }
};


int main() {
    return 0;
}
