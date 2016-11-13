#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// use next_permutation in 031-NextPermutation or STL
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

