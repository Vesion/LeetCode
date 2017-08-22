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
        deque<int> q;
        for (int i = 0; i < (int)nums.size(); ++i) {
            while (!q.empty() && nums[i] > nums[q.back()]) q.pop_back();
            q.push_back(i);
            if (i-q.front()+1 > k) q.pop_front();
            if (i >= k-1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};


int main() {
    return 0;
}
