#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) --k;
            while (k < 0) {
                if (nums[j++] == 0) ++k;
            }
            res = max(res, i-j+1);
        }
        return res;
    }
};

int main() {
}
