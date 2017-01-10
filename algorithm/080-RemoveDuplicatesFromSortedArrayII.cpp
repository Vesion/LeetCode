#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int d = 2; // for general case, duplicates are allowed at most d times
        if (nums.size() < d) return nums.size();
        int k = d;
        for (int i = d; i < (int)nums.size(); ++i) {
            if (nums[i] != nums[k-d]) nums[k++] = nums[i];
        }
        return k;
    }
};


int main() {
    return 0;
}

