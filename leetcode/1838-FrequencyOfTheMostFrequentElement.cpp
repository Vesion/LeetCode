#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


// two pointers
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        using ll = long long; ll sum = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum + k < ll(nums[i]) * (i-j+1)) {
                sum -= nums[j++];
            }
            res = max(res, i-j+1);
        }
        return res;
    }
};

int main() {

}