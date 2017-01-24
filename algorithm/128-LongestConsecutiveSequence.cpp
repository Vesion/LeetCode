#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
#include <unordered_set> 
#include <unordered_map> 
using namespace std;

// Solution 1 : hash table, O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int num : nums) {
            int left = num-1, right = num+1;
            while (s.count(left)) s.erase(left--);
            while (s.count(right)) s.erase(right++);
            res = max(res, right-left-1);
        }
        return res;
    }
};


// Solution 2 : union find, O(n*(log*n))
class Solution_2 {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();

        root.resize(n, 0);
        iota(root.begin(), root.end(), 0);
        length.resize(n, 1);
        
        unordered_map<int, int> m; // { num : id }
        for (int i = 0; i < n; ++i) {
            if (m.count(nums[i])) continue;
            m[nums[i]] = i;
            if (m.count(nums[i]-1)) unionSet(i, m[nums[i]-1]);
            if (m.count(nums[i]+1)) unionSet(i, m[nums[i]+1]);
        }
        return *max_element(length.begin(), length.end());
    }
    
    vector<int> root;   // root of this set
    vector<int> length; // size of this set
    
    int findRoot(int i) {
        if (root[i] != i) root[i] = findRoot(root[i]);
        return root[i];
    }
    
    void unionSet(int i, int j) {
        int ri = findRoot(i), rj = findRoot(j);
        if (ri == rj) return;
        if (length[ri] < length[rj]) {
            root[ri] = rj;
            length[rj] += length[ri];
        } else {
            root[rj] = ri;
            length[ri] += length[rj];
        }
    }
};


int main() {
    Solution s;
    vector<int> nums = {100, 200, 1, 10, 2, 4, 3};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}

