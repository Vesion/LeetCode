#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for (int num : nums) {
            if (num == first || num == second || num == third) continue;
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }
        return third == LONG_MIN ? first : third;
    }
};


int main() {
    Solution s;
    vector<int> nums = {INT_MIN, INT_MIN,2,2,2};
    cout << s.thirdMax(nums) <<endl;;
    return 0;
}
