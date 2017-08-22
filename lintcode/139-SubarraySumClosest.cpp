#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


// Similar to 138-SubarraySum, use map to store {sum, i}
class Solution {
public:
    vector<int> subarraySumClosest(vector<int> nums){
        int n = nums.size();
        int gap = INT_MAX; vector<int> result = {0, 0};
        map<int, int> m;
        m[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            auto itlow = m.lower_bound(sum);
            if (itlow == m.end()) --itlow;
            if (abs(itlow->first-sum) < gap) {
                gap = abs(itlow->first-sum);
                result = {itlow->second+1, i};
            }
            m[sum] = i;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {INT_MAX};
    auto r = s.subarraySumClosest(nums);
    for (auto i : r) cout << i << " "; cout << endl;
    return 0;
}
