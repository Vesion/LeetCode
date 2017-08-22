#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> 
using namespace std;


// The general form of Majority Number Problem
// Given an array of integers and a number k, the majority number is the number that occurs more than 1/k of the size of the array.
//
// Boyer Moore Voting Algorithm

class Solution {
public:
    int majorityNumber(vector<int> nums, int k) {
        vector<int> c(k, 0), r(k);
        iota(r.begin(), r.end(), 0);
        for (auto & num : nums) {
            bool voted = false;
            for (int i = 0; i < k; ++i) {
                if (num == r[i]) { ++c[i]; voted = true; break; }
                else if (c[i] == 0) { c[i] = 1; r[i] = num; voted = true; break; }
            }
            if (!voted) for (int i = 0; i < k; ++i) --c[i];
        }

        for (auto i : r) cout << i << " "; cout << endl;
        for (auto i : c) cout << i << " "; cout << endl;

        fill(c.begin(), c.end(), 0);
        for (auto & num : nums) {
            for (int i = 0; i < k; ++i) {
                if (num == r[i]) ++c[i];
                if (c[i] > (int)nums.size()/k) return r[i];
            }
        }

        return -1; // never
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,1,2,3,2,3,3,4,4,4};
    cout << s.majorityNumber(nums, 3) << endl;
    return 0;
}
