#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(),
             [](int a, int b) {
                 return to_string(a)+to_string(b) > to_string(b)+to_string(a);
             });
        if (nums[0] == 0) return "0";
        string res;
        for (int num : nums) res += to_string(num);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,0};
    cout << s.largestNumber(nums) << endl;
    return 0;
}

