#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> m;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            if (j-i > k) m.erase(nums[i++]);
            if (m.count(nums[j])) return true;
            m.insert(nums[j]);
        }
        return false;
    }
};


int main() {
    return 0;
}
