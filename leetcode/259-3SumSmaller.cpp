#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // think about why we can sort it
        int res = 0;
        for (int i = 0; i+2 < n; ++i) {
            int t = target-nums[i];
            int j = i+1, k = n-1;
            while (j < k) {
                if (nums[j]+nums[k] < t) {
                    res += k-j; // all pairs in [j, k] (j < k) are valid
                    ++j;
                } else --k;
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
