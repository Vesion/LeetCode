#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// The classical shuffle algorithm: Fisher Yates Algorithm
class Solution {
private:
    vector<int> origin, nums;
public:
    Solution(vector<int> nums) {
        this->origin = this->nums = nums;
    }

    vector<int> reset() {
        nums = origin;
        return nums;
    }

    vector<int> shuffle() {
        for (int i = nums.size()-1; i >= 0; --i) {
            // correctness proof:
            // int j = rand()%(i+1)
            // if j == i, no swap, p = 1/(i+1)
            // if j < i, swap, p = (1-1/(i+1))*(1/i) = 1/(1+1)
            swap(nums[i], nums[rand()%(i+1)]);
        }
        return nums;
    }
};


int main() {
    return 0;
}
