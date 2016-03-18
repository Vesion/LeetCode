#include <iostream>
#include <vector>
using namespace std;

// Solution 1 : similar to bubble sort, O(n^2) time
void moveZeroes_On2(vector<int>& nums) {
    if (nums.empty()) return;
    bool s = false;
    for (int i = nums.size()-1; i >= 1; --i) {
        for (int j = 0; j < i; ++j)
            if (nums[j] == 0) { swap(nums[j], nums[j+1]); s = true; }
        if (!s) break;
    }
}


// Solution 2 : one pass, put thoses numbers greater than 0 to left in order, than the rest part set to 0, O(n)
void moveZeroes_On(vector<int>& nums) {
    if (nums.empty()) return;
    int n = nums.size();
    int left = 0;
    for (int i = 0; i < n; ++i)
        if (nums[i]) nums[left++] = nums[i];
    for (; left < n; ++left) if (nums[left]) nums[left] = 0;
}

int main() {
    vector<int> nums = {1, 0, 1};
    //moveZeroes_On2(nums);
    moveZeroes_On(nums);
    for (auto i:nums) cout << i << " "; cout << endl;
    return 0;
}
