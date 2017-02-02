#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> nums(length, 0);
        for (auto& u : updates) {
            nums[u[0]] += u[2]; // range start
            if (u[1]+1 < length) nums[u[1]+1] -= u[2]; // range end
        }
        int inc = 0;
        for (int i = 0; i < length; ++i) {
            inc += nums[i];
            nums[i] = inc;
        }
        return nums;
    }
};


int main() {
    Solution s;
    vector<vector<int>> u = {
        {1,3,2},
        {2,4,3},
        {0,2,-2},
    };
    auto r = s.getModifiedArray(5, u);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
