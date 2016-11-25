#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) return "";
        sort(nums.begin(), nums.end(), [](const int n1, const int n2) {
                return to_string(n1)+to_string(n2) > to_string(n2)+to_string(n1); });
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

