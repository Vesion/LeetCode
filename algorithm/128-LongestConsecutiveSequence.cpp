#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// use unordered_map
int longestConsecutive_map(vector<int>& nums) {
    int result = 0;
    unordered_map <int, bool> used;
    for (auto & i : nums) used[i] = false;

    for (auto & num : nums) {
        if (used[num]) continue;
        used[num] = true;
        int length = 1;
        for (int left = num-1; used.find(left) != used.end(); --left) {
            used[left] = true;
            ++length;
        }
        for (int right = num+1; used.find(right) != used.end(); ++right) {
            used[right] = true;
            ++length;
        }
        result = max(result, length);
    }
    return result;
}

// use unordered_set, same with above
int longestConsecutive_set(vector<int>& nums) {
    int result = 0;
    unordered_set<int> unused {nums.begin(), nums.end()};
    
    for (auto & num : nums) {
        if (unused.find(num) == unused.end()) continue;
        unused.erase(num);
        int left, right;
        for (left = num-1; unused.find(left) != unused.end(); --left) unused.erase(left);
        for (right = num+1; unused.find(right) != unused.end(); ++right) unused.erase(right);
        result = max(result, right-left-1);
    }
    return result;
}

int main() {
    vector<int> nums {100, 9, 1, 4, 0, 3, 2, 10};
    cout << longestConsecutive_map(nums);
    cout << longestConsecutive_set(nums);
    return 0;
}
