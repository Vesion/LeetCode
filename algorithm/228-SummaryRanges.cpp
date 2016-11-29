#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        int start = nums[0];
        vector<string> res;
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i-1]+1 < nums[i]) {
                res.push_back(getRange(start, nums[i-1]));
                start = nums[i];
            }
        }
        res.push_back(getRange(start, nums.back()));
        return res;
    }
    
    string getRange(int n1, int n2) {
        if (n1 == n2) return to_string(n1);
        return to_string(n1) + "->" + to_string(n2);
    }
};

int main() {
    Solution s;
    return 0;
}
