#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n);
        partial_sum(nums.begin(), nums.end(), sums.begin());
        for (int i = 0; i < n; ++i) {
            int left = i == 0 ? 0 : sums[i-1];
            int right = sums[n-1] - sums[i];
            if (left == right) return i;
        }
        return -1;
    }
};


int main() {
    return 0;
}
