#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque> 
using namespace std;

// Maintain a monotonically decreasing deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < (int)nums.size(); ++i) {
            while (!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if (i-dq.front() >= k) dq.pop_front();
            if (i+1 >= k) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};


int main() {
    return 0;
}
