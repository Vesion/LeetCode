#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// simialr to 325-MaximumSizeSubarraySumEqualsK
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0, sum = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i] == 0 ? -1 : 1;
            auto it = m.find(sum);
            if (it != m.end()) res = max(res, i-it->second);
            else m[sum] = i;
        }
        return res;
    }
};


int main() {
    return 0;
}
