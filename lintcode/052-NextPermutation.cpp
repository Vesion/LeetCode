#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> nextPermutation(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return nums;

        vector<int> result = nums;
        int i = n-2, i1 = n-1, i2 = n-1;
        while (i >= 0) {
            if (result[i] < result[i1]) break;
            else --i, --i1;
        }
        if (i < 0) {
            reverse(result.begin(), result.end());
            return result;
        }
        while (i2 > i) {
            if (result[i2] > result[i]) break;
            else --i2;
        }
        swap(result[i], result[i2]);
        reverse(result.begin()+i1, result.end());
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1};
    auto r = s.nextPermutation(nums);
    for (auto i : r) cout << i << " "; cout << endl;
    return 0;
}
