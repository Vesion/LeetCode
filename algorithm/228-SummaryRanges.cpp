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
            if (nums[i] > nums[i-1]+1) {
                res.push_back(getRange(start, nums[i-1]));
                start = nums[i];
            }
        }
        res.push_back(getRange(start, nums.back()));
        return res;
    }
    
    string getRange(int start, int end) {
        string r = to_string(start);
        if (start < end) r += "->" + to_string(end);
        return r;
    }
};


int main() {
    return 0;
}
