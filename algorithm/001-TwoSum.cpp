#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (m.count(target-nums[i])) return {m[target-nums[i]], i};
            m[nums[i]] = i;
        }
        return {};
    }
};


int main() {
    return 0;
}
