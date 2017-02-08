#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

// Based on 496-NextGreaterElementI, learn to use stack.
// extend array to double size to deal with circularity, 
// but here we use mod trick, rather than real extending

// Solution 1 : iterate from back to front
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 2*n-1; i >= 0; --i) {
            int num = nums[i%n];
            while (!st.empty() && nums[st.top()] <= num) st.pop();
            res[i%n] = st.empty() ? - 1 : nums[st.top()];
            st.push(i%n);
        }
        return res;
    }
};


// Solution 2 : iterate from front to back
class Solution_2 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) return {};
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < 2*n; ++i) {
            int num = nums[i%n];
            while (!st.empty() && nums[st.top()] < num) {
                res[st.top()] = num;
                st.pop();
            }
            if (i < n) st.push(i);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums = {1,1,1,2,1,1};
    auto r = s.nextGreaterElements(nums);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}
