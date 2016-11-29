#include <iostream>
#include <vector>
using namespace std;

// Similar to 169-MajorityElement, this problem require majority for more than ceiling of n/3, so we need to maintain two majorities and two counters.

// Boyer-Moore Majority Vote algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int res1 = -1, votes1 = 0;
        int res2 = -2, votes2 = 0;
        for (int num : nums) {
            if (num == res1) ++votes1;
            else if (num == res2) ++votes2;
            else {
                if (votes1 == 0) res1 = num, votes1 = 1;
                else if (votes2 == 0) res2 = num, votes2 = 1;
                else --votes1, --votes2;
            }
        }
        votes1 = votes2 = 0;
        for (int num : nums) {
            if (num == res1) ++votes1;
            else if (num == res2) ++ votes2;
        }
        vector<int> res;
        if (votes1 > nums.size()/3) res.push_back(res1);
        if (votes2 > nums.size()/3) res.push_back(res2);
        return res;
    }
};

int main() {
    return 0;
}
