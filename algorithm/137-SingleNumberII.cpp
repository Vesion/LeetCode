#include <iostream>
#include <vector>
using namespace std;

// Solution 1 : O(w*n) time, w is sizeof(int), O(1) space
// bit operation, count '1's of all 32 bits, there must be at least one bit, the number of '1's on it cannot mod 3
int singleNumber_mod(vector<int>& nums) {
    const int W = sizeof(int);
    int count[W] = {0};
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < W; ++j) {
            if (nums[i] >> j & 1) ++count[j];
            count[j] %= 3;
        }
    }
    // now count is result's binary representation
    int result = 0;
    for (int i = 0; i < W; ++i)
        if (count[i] == 1) result |= (1 << i);
    return result;
}


// Solution 2 : O(n) time, O(1) space, much faster
// refer to https://leetcode.com/discuss/6632/challenge-me-thx
// 其实就是solution1的bitmap版，不用int数组来存储每个位上1的个人，而是直接用int来存储，因为每个数最多出现3次，所以用两个int来模拟三进制即可
int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); ++i) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
        cout << nums[i] << " " << ones << " " << twos << endl;
    }
    return ones;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 2, 3};
    cout << singleNumber_mod(nums) << endl;
    cout << singleNumber(nums) << endl;
    return 0;
}
