#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : enumerate, O(n) time, be careful with duplicates
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if  (nums.size() < 3)
            return *max_element(nums.begin(), nums.end());
        
        int top3[3] = {INT_MIN, INT_MIN, INT_MIN,};
        for (auto n : nums) {
            if (n > top3[0] && n != top3[1] && n != top3[2]) {
                top3[0] = n;
                if (top3[0] > top3[1])
                    swap(top3[0], top3[1]);
                if (top3[1] > top3[2])
                    swap(top3[1], top3[2]);
            }
        }
        return top3[0];
    }
};

int main() {
    Solution s;
    vector<int> nums = {INT_MIN, INT_MIN, 1, 2, 2, 2, 3};
    cout << s.thirdMax(nums) <<endl;;
    return 0;
}
