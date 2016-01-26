#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int reach = 0;
    for (int i = 0; i <= reach && i < nums.size(); ++i) {
        reach = max(reach, i + nums[i]);
    }
    return reach >= nums.size()-1;
}

int main() {
    vector<int> nums = {1, 1, 1};
    cout << canJump(nums) << endl;
    return 0;
}
