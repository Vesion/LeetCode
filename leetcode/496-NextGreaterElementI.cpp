#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

// Mono-decreasing stack
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        unordered_map<int,int> ng;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && st.top() < nums2[i]) {
                ng[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        int m = nums1.size();
        vector<int> res(m);
        for (int i = 0; i < m; ++i)
            res[i] = ng.count(nums1[i]) ? ng[nums1[i]] : -1;
        return res;
    }
};

int main() {
    return 0;
}
