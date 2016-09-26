#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to '001-TwoSum.cpp', but here array is sorted


// Solution 1 : two pointers, O(n) time
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) break;
            if (sum < target) ++left;
            else --right;
        }
        return {left+1, right+1};
    }
};


// Solution 2 : binary search, O(nlogn) time
class Solution_bs {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (auto left = numbers.begin(); left != numbers.end()-1; ++left) {
            auto right = lower_bound(left+1, numbers.end(), target-*left);
            if (*left + *right == target) return {(int)(left-numbers.begin())+1, (int)(right-numbers.begin())+1};
        }
        return {0, 0}; // never
    }
};

int main() {
    Solution s;
    return 0;
}
