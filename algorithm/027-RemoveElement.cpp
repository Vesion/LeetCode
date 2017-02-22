#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < (int)nums.size(); ++j) {
            if (nums[j] != val) nums[i++] = nums[j];
        }
        return i;
    }
};


int main() {
    return 0;
}
