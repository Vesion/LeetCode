#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// dp, similar to 001-TwoSum, O(N)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> c;
        int res = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == k) ++res;
            if (c.count(sum-k)) res += c[sum-k];
            ++c[sum];
        }
        return res;
    }
};


int main() {
    return 0;
}
