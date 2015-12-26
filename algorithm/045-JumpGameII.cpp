#include <iostream>
#include <vector>
using namespace std;

// solution1 : common solution, dfs
// TLE
int dfs(vector<int>& nums, int start, int steps) {
    if (start == nums.size()-1) {
        //cout << "end " << steps << endl;
        return steps;
    }
    int result = INT_MAX;
    for (int i = start + 1; i < nums.size() && i <= start + nums[start]; ++i) {
        //cout << "from " << start << " to " << i << endl;
        int tmp = dfs(nums, i, steps + 1);
        if (result > tmp) {
            result = tmp;
        }
    }
    return result;
}

int jump_dfs(vector<int>& nums) {
    int steps = dfs(nums, 0, 0);
    return steps;
}

// solution2 : greedy
// iterate from [left, right] to find the farthest new_right, then [right+1, new_right] 
// O(n), O(1)
int jump_greedy1(vector<int>& nums) {
    if (nums.size() == 1)
        return 0;
    int left = 0, right = 0;
    int steps = 0;
    while (true) {
        steps += 1;
        int old_right = right;
        for (int i = left; i <= old_right; ++i) {
            int new_right = i + nums[i];
            if (new_right >= nums.size() - 1) {
                return steps;
            }
            if (right < new_right) {
                right = new_right;
            }
        }
        left = old_right + 1;
    }
    return 0;
}

// solution3 : greedy2
// cur stores the potantial farthest position, last stores the last farthest position, if i > last, jump
// O(n), O(1)
int jump(vector<int>& nums) {
    int steps = 0;
    int last = 0, cur = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > last) {
            last = cur;
            steps += 1;
        }
        cur = max(cur, i + nums[i]);
    }
    return steps;
}

int main() {
    vector<int> a({2, 3, 1, 1, 4});
    cout << jump(a) << endl;
    return 0;
}
