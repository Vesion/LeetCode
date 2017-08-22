#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// the classical 'three way partition' problem
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size()-1, k = 0;
        while (k <= j) {
            if (nums[k] == 0) swap(nums[i++], nums[k++]);
            else if (nums[k] == 2) swap(nums[j--], nums[k]); // keep k staying here, in case of 0 comes from back end
            else ++k;
        }
    }
};


int main() {
    return 0;
}
