#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <unordered_map>
using namespace std;

// Solution 1 : sort, two pointers, O(nlogn) time, O(1) space
// but here we are required to return indexes, so we need extra space to record index
class Solution_1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> index(n);
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&nums](const int& i1, const int& i2) {
            return nums[i1] < nums[i2];
        });
        int i = 0, j = n-1;
        while (i < j) {
            if (nums[index[i]]+nums[index[j]] == target) break;
            if (nums[index[i]]+nums[index[j]] < target) ++i;
            else --j;
        }
        return {index[i], index[j]};
    }
};


// Solution 2 : hash table, O(n) time, O(n) space
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (m.count(target-nums[i])) return {m[target-nums[i]], i};
            m[nums[i]] = i;
        }
        return {};
    }
};


int main() {
    return 0;
}
