#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
                return to_string(a)+to_string(b) > to_string(b)+to_string(a); });
        string result;
        for (auto &num : nums) result += to_string(num);
        return result[0] == '0' ? "0" : result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 20, 23, 4, 8};
    cout << s.largestNumber(nums) << endl;
    return 0;
}
