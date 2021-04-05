#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;

// BST, O(nlogk)
class Solution0 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> m;
        vector<multiset<int>::iterator> its(n);
        vector<int> res;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            its[i] = m.insert(nums[i]);
            if (i-j+1 > k) m.erase(its[j++]);
            if (i-j+1 == k) res.push_back(*m.rbegin());
        }
        return res;
    }
};

// monotonically decreasing deque
// similar to 1499-MaxValueOfEquation
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < (int)nums.size(); ++i) {
            while (!q.empty() && nums[i] > nums[q.back()]) q.pop_back();
            q.push_back(i);
            while (!q.empty() && i-q.front()+1 > k) q.pop_front();
            if (i >= k-1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};


int main() {
    return 0;
}
