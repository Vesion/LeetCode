#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;


// Solution 1 : 3 cases : a = 0, a < 0, a > 0
class Solution_1 {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        if (n <= 1) return nums;

        if (a == 0) { // linear function
            transform(nums.begin(), nums.end(), nums.begin(), [=](const int x) { return b*x+c; });
            if (b < 0) reverse(nums.begin(), nums.end());
            return nums;
        }

        auto quadratic = [=](const int x) { return a*x*x + b*x + c; };
        float midx = -1.0 * b / (2*a);

        int i = 0, j = n-1;
        vector<int> res;
        while (i <= j) {
            if (fabs(nums[i]-midx) > fabs(nums[j]-midx)) res.push_back(quadratic(nums[i++]));
            else res.push_back(quadratic(nums[j--]));
        }
        if (a > 0) reverse(res.begin(), res.end());
        return res;
    }
};


// Solution 2 : 2 cases
//      1. a > 0, two ends in original array are bigger than center
//      2. a < 0, center is bigger than two ends
//              so use two pointers i, j and do a merge-sort like process. depending on sign of a, start from the beginning or end of the transformed array. 
//      3. a == 0, it does not matter what b's sign is, the function is monotonically increasing or decreasing. you can start with either beginning or end.
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        if (n <= 1) return nums;

        auto quadratic = [=](const int x) { return a*x*x + b*x + c; };
        int i = 0, j = n-1;
        vector<int> res(n);
        int k = a >= 0 ? n-1 : 0;

        while (i <= j) {
            if (a >= 0)
                res[k--] = quadratic(nums[i]) >= quadratic(nums[j]) ? quadratic(nums[i++]) : quadratic(nums[j--]);
            else
                res[k++] = quadratic(nums[i]) >= quadratic(nums[j]) ? quadratic(nums[j--]) : quadratic(nums[i++]);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums = {-4,-2,2,4};
    auto r = s.sortTransformedArray(nums, -1, 3, 5);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
