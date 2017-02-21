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
        unordered_map<int, int> m;
        m[0] = -1;
        int res = 0, c = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            c += nums[i] == 0 ? -1 : 1;
            if (m.count(c)) res = max(res, i-m[c]);
            m.insert({c, i});
        }
        return res;
    }
};


int main() {
    return 0;
}
