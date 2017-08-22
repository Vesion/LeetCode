#include <iostream>
#include <vector>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    // use hashmap to store {sum, i}, where sum is accumulating from index 0 to i
    // check sum each time if it has occurred, if occurred, the sum of subarray from last occurred to this is 0
    vector<int> subarraySum(vector<int> nums){
        int n = nums.size();
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (m.count(sum)) return {m[sum]+1, i};
            m[sum] = i;
        }
        return {}; // never
    } 
};

int main() {
    Solution s;
    auto r = s.subarraySum({1, 2, 0});
    cout << r[0] << " " << r[1] << endl;;
    return 0;
}
