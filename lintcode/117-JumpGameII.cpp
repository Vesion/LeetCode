#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> 
using namespace std;

// Solution 1 : greedy, jump to the farthest index on each step
class Solution {
public:
    int jump(vector<int> nums) {
        int steps = 0;
        int cur = 0, last = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (i > last) {
                last = cur;
                ++steps;
            }
            cur = max(cur, i+nums[i]);
        }
        return steps;
    }
};


// Solution 2 : bfs, memory limit exceeded
class Solution_2 {
public:
    int jump(vector<int>& nums) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto n = q.front(); q.pop();
            if (n.first == (int)nums.size()-1) return n.second;
            for (int i = 1; i <= nums[n.first]; ++i)
                q.push({n.first+i, n.second+1});
        }
        return 0;
    }
};


int main() {
    vector<int> nums = {2,3,1,1,4};

    Solution s;
    cout << s.jump(nums) << endl;
    Solution_2 s2;;
    cout << s2.jump(nums) << endl;
    return 0;
}
