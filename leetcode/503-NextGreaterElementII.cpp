#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// Based on 496-NextGreaterElementI, learn to use stack.
// extend array to double size to deal with circularity,
// but here we use mod trick, rather than real extending
// Mono-decreasing stack
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
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
}
