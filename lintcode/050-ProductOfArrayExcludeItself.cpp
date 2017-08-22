#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> productExcludeItself(vector<int> &nums) {
        int n = nums.size();
        vector<long long> prefix(n+1, 1), suffix(n+1, 1), result(n);
        for (int i = 1; i <= n; ++i) prefix[i] = prefix[i-1] * nums[i-1];
        for (int i = n-1; i >= 0; --i) {
            suffix[i] *= suffix[i+1] * nums[i];
            result[i] = prefix[i] * suffix[i+1];
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0};
    auto r = s.productExcludeItself(nums);
    for (auto i : r) cout << i << " ";
    return 0;
}
