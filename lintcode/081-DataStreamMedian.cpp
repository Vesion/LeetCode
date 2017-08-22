#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

class Solution {
public:
    vector<int> medianII(vector<int> &nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        vector<int> result(n);
        priority_queue<int> maxq;
        priority_queue<int, vector<int>, greater<int>> minq;

        for (int i = 0; i < n; ++i) {
            minq.push(nums[i]);
            maxq.push(minq.top());
            minq.pop();
            if (minq.size() < maxq.size()-1) {
                minq.push(maxq.top());
                maxq.pop();
            }
            result[i] = maxq.top();
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    auto r = s.medianII(nums);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
