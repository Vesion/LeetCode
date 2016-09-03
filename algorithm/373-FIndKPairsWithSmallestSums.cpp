#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;


// A much more faster solution:
// https://discuss.leetcode.com/topic/50481/clean-16ms-c-o-n-space-o-klogn-time-solution-using-priority-queue/2
//
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> r;

        int n1 = nums1.size(), n2 = nums2.size();    
        if (n1 == 0 || n2 == 0 || k <= 0) return r;

        auto comp = [&nums1, &nums2](pair<int, int> p1, pair<int, int> p2) {
            return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> rq(comp);

        rq.emplace(0, 0);
        while (k-- > 0 && !rq.empty()) {
            auto id = rq.top(); rq.pop();
            r.emplace_back(nums1[id.first], nums2[id.second]);
            if (id.first+1 < n1) 
                rq.emplace(id.first+1, id.second);
            if (id.first == 0 && id.second+1 < n2) // this is the core reason for being much faster
                rq.emplace(id.first, id.second+1);
        }
        return r;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {1, 2, 3};
    auto r = s.kSmallestPairs(nums1, nums2, 10);
    for (auto i : r) cout << i.first << " " << i.second <<endl;
    return 0;
}
