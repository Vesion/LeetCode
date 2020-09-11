#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// using std
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        if (left == nums.end() || *left != target) return {-1, -1};
        auto right = upper_bound(nums.begin(), nums.end(), target);
        return {int(left-nums.begin()), int(right-nums.begin()-1)};

    }
};

class Solution1 {
public:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            const int mid = left + (right-left)/2;
            if (nums[mid] < target) left = mid+1;
            else right = mid;
        }
        return left;
    }

    int upper_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            const int mid = left + (right-left)/2;
            if (nums[mid] <= target) left = mid+1;
            else right = mid;
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        const int l = lower_bound(nums, target);
        if (l == nums.size() || nums[l] != target) return {-1, -1};
        return {l, upper_bound(nums, target)-1};
    }
};

int main() {
    return 0;
}
