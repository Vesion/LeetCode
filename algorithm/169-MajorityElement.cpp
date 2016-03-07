#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Same with the book "Beauty of Programming"--problem2.3

// Solution 1 : sort nums, the majority element must be the middle one, O(nlgn) time
int majorityElement_sort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}

// Solution 2 : use map count each num, O(n) time, O(n) space
int majorityElement_map(vector<int>& nums) {
    unordered_map<int, int> m; 
    for (auto & num : nums) {
        ++m[num];
        if (m[num] > nums.size()/2) return num;
    }
    return 0; // never
}

// Solution 3 : divide and conquer, O(n) time
int majority(vector<int>& nums, int left, int right) {
    if (left == right) return nums[left];
    int mid = left + ((right - left) >> 1);
    int lm = majority(nums, left, mid);
    int rm = majority(nums, mid + 1, right);
    if (lm == rm) return lm;
    return count(nums.begin() + left, nums.begin() + right + 1, lm) > count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
}

int majorityElement_dc(vector<int>& nums) {
    return majority(nums, 0, nums.size() - 1);
}

// Solution 4 : Moore Voting Algorithm, well done, O(n) time, O(1) space
int majorityElement_vote(vector<int>& nums) {
    int majority;
    int times = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (times == 0) majority = nums[i], times = 1;
        else {
            if (majority == nums[i]) ++times;
            else --times;
        }
    }
    return majority;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 1, 1, 1};
    cout << majorityElement_sort(nums) << endl;
    cout << majorityElement_map(nums) << endl;
    cout << majorityElement_dc(nums) << endl;
    cout << majorityElement_vote(nums) << endl;
    return 0;
}
