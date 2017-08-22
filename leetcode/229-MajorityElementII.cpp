#include <iostream>
#include <vector>
using namespace std;

// Similar to 169-MajorityElement, this problem require majority for more than ceiling of n/3, so we need to maintain two majorities and two counters.

// Boyer-Moore Majority Vote algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int r1 = 0, c1 = 0, r2 = 1, c2 = 0;
        for (int& num : nums) {
            if (num == r1) ++c1;
            else if (num == r2) ++c2;
            else {
                if (c1 == 0) { r1 = num; c1 = 1; }
                else if (c2 == 0) { r2 = num; c2 = 1; }
                else { --c1; --c2; }
            }
        }
        c1 = c2 = 0;
        for (int& num : nums) {
            if (num == r1) ++c1;
            else if (num == r2) ++c2;
        }
        vector<int> res;
        if (c1 > (int)nums.size()/3) res.push_back(r1);
        if (c2 > (int)nums.size()/3) res.push_back(r2);
        return res;
    }
};

int main() {
    return 0;
}
