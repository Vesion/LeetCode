#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

// Solution 1 : counting sort
class Solution_1 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();    
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i+1) {
                if (nums[nums[i]-1] == nums[i]) break;
                int id = nums[i]-1;
                swap(nums[id], nums[i]);
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i+1) result.push_back(nums[i]);
        }
        return result;
    }
};


// Solution 2 : flip number to negative
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            int id = abs(nums[i])-1;
            if (nums[id] < 0) result.push_back(abs(id+1));
            nums[id] = -nums[id];
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    for (int i = 1; i <= 100; ++i) nums.push_back(i);
    for (int i = 1; i <= 100; ++i) nums.push_back(i);
    auto r = s.findDuplicates(nums);
    for (auto& e : r) cout << e << " "; cout << endl; 
}
