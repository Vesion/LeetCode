#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (s.count(nums[i])) return true;
            s.insert(nums[i]);
            if ((int)s.size() > k) s.erase(nums[i-k]);
        }
        return false;
    }
};


int main() {
    return 0;
}
