#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (auto & num : nums)
        result ^= num;
    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 1, 2, 3, 4};
    cout << singleNumber(nums) << endl;
    return 0;
}
