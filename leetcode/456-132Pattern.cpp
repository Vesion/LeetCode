#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
#include <set> 
using namespace std;


// Solution 1 : two passes, O(nlongn)
class Solution_1 {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        set<int> rs;

        vector<int> rm(n, INT_MIN); // rm[i] is the max number to i's right and smaller than nums[i]
        rs.insert(nums[n-1]);
        for (int i = nums.size()-2; i > 0; --i) {
            auto it = rs.lower_bound(nums[i]);
            if (it != rs.begin()) rm[i] = *(--it);
            rs.insert(nums[i]);
        }

        rs.clear();
        vector<int> lm(n, INT_MAX); // lm[i] is the min number to i's left and smaller than nums[i]
        rs.insert(nums[0]);
        for (int i = 1; i < n-1; ++i) {
            auto it = rs.lower_bound(nums[i]);
            if (it != rs.begin()) lm[i] = *rs.begin();
            rs.insert(nums[i]);
        }

        for (int i = 1; i < n-1; ++i) {
            if (rm[i] > lm[i]) return true;
        }
        return false;
        
    }
};


// Solution 2 : stack, one pass, O(n)
// Scan from back to front, use a stack to store largest numbers, a2 to store second largest number
// we ensure numbers in stack is larger than a2
// once we find a number is smaller than a2, we find a 132 pattern (a1 is current number, a3 is any one in stack, a2 is a2)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int a2 = INT_MIN;
        for (int i = (int)nums.size()-1; i >= 0; --i) {
            if (nums[i] < a2) return true;
            while (!st.empty() && nums[i] > st.top()) {
                a2 = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<int> nums = {3,5,0,3,4};
    cout << s.find132pattern(nums) <<endl;
    return 0;
}
