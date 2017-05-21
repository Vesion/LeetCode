#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxx = INT_MIN, right = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < maxx) right = i;
            maxx = max(maxx, nums[i]);
        }
        int minx = INT_MAX, left = 1;
        for (int i = n-1; i >= 0; --i) {
            if (nums[i] > minx) left = i;
            minx = min(minx, nums[i]);
        }
        return right-left+1;
    }
};


int main() {
    return 0;
}
