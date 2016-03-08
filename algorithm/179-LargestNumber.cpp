#include <iostream>
#include <string>
#include <vector>
using namespace std;

// do NOT make trouble to compare two integers, instead compare string
string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](const int& x, const int& y) {
            return to_string(x) + to_string(y) > to_string(y) + to_string(x); });
    if (nums[0] == 0) return "0";
    string result;
    for (auto & num : nums) result += to_string(num);
    return result;
}

int main() {
    vector<int> nums = {0, 0};
    cout << largestNumber(nums) << endl;
    return 0;
}
