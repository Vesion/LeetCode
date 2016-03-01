#include <iostream>
#include <vector>
using namespace std;

// similiar to 136
// firstly use XOR in one scan to get the diff, then find the first set bit, then nums can be divided into two groups with that bit set or not, XOR them respectively
vector<int> singleNumber(vector<int>& nums) {
    int diff = 0;
    for (auto & num : nums)
        diff ^= num;
    diff &= -diff; // get the first set bit
    
    vector<int> result(2, 0);
    for (auto & num : nums) {
        if (num & diff) result[0] ^= num;
        else result[1] ^= num;
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 2};
    auto result = singleNumber(nums);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
