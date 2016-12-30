#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
using namespace std;

// A math problem
// The key is: Incrementing all but one is equivalent to decrementing that one. 
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_num = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (int num : nums) res += num-min_num;
        return res;
    }
};


int main() {
    Solution s;
    return 0;
}

