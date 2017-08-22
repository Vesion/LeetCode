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
            swap(nums[i], nums[rand()%(i+1)]);
        }
        return nums;
    }
};


int main() {
    return 0;
}
