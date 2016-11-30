#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque> 
using namespace std;

// Maintain a monotonic queue
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); ++i) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if (!dq.empty() && dq.front() <= i-k) dq.pop_front();
            if (i >= k-1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}
