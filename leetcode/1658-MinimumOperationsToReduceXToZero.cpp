#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// convert to calculate the longest subarray which sum to t
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (int num : nums) sum += num;
        x = sum - x;
        int res = -1;
        sum = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (j <= i && sum > x) sum -= nums[j++];
            if (sum == x) res = max(res, i-j+1);
        }
        return res == -1 ? -1 : nums.size() - res;
    }
};

int main() {

}
