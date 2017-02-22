#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;
        if ((int)nums.size() < k) return nums.size();
        int r = k;
        for (int i = k; i < (int)nums.size(); ++i) {
            if (nums[i] != nums[r-k]) nums[r++] = nums[i];
        }
        return r;
    }
};


int main() {
    return 0;
}

