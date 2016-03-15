#include <iostream>
#include <vector>
using namespace std;

// Similar to 169-MajorityElement, this problem require majority for more than ceiling of n/3, so we need to maintain two majorities and two counters.

// Boyer-Moore Majority Vote algorithm
vector<int> majorityElement(vector<int>& nums) {
    int m1 = 0, m2 = 1; // init with different value for different reassignment condition
    int c1 = 0, c2 = 0;
    for (auto & num : nums) {
        if (num == m1) ++c1;
        else if (num == m2) ++c2;
        else if (c1 == 0) m1 = num, c1 = 1;
        else if (c2 == 0) m2 = num, c2 = 1;
        else --c1, --c2;
    }
    c1 = c2 = 0;
    for (auto & num : nums) {
        if (num == m1) ++c1;
        else if (num == m2) ++c2;
    }
    vector<int> result;
    int n = nums.size();
    if (c1 > n/3) result.push_back(m1);
    if (c2 > n/3) result.push_back(m2);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    auto v = majorityElement(nums);
    for (auto i:v) cout << i << endl;
    return 0;
}
