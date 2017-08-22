#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <stack> 
using namespace std;

// learn to use stack to maintain monotonically increasing/decreasing sequence

// Solution 1 : iterate from back to front
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        if (findNums.empty()) return {};
        int n = nums.size();
        unordered_map<int, int> ng;
        stack<int> st;
        for (int i = n-1; i >= 0; --i) {
            while (!st.empty() && st.top() < nums[i]) st.pop(); // try to find the right most recent greater number
            ng[nums[i]] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        
        int m = findNums.size();
        vector<int> res(m);
        for (int i = 0; i < m; ++i) res[i] = ng[findNums[i]];
        return res;
    }
};


// Solution 2 : iterate from front to back
class Solution_2 {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        if (findNums.empty()) return {};
        int n = nums.size();
        unordered_map<int, int> ng;
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && st.top() < nums[i]) { // for a new number, update ng of smaller numbers in stack
                ng[st.top()] = nums[i];
                st.pop();
            }
            st.push(nums[i]);
        }
        
        int m = findNums.size();
        vector<int> res(m);
        for (int i = 0; i < m; ++i) res[i] = ng.count(findNums[i]) ? ng[findNums[i]] : -1;
        return res;
    }
};


int main() {
    return 0;
}
