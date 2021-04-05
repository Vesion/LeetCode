#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
using namespace std;


// Sort, O(NlogN) time, O(1) space
class Solution0 {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0, d = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) ++d;
            else {
                if (nums[i] == nums[i-1]+1) ++d;
                else if (nums[i] > nums[i-1]+1) d = 1;
            }
            res = max(d, res);
        }
        return res;
    }
};

// Solution 1 : hash table, O(N) time, O(N) space
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


// Solution 2 : union find, O(N) time, O(N) space
class Solution2 {
public:
    vector<int> root;
    vector<int> count;
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        root.resize(n); iota(root.begin(), root.end(), 0);
        count.resize(n, 1);

        unordered_map<int,int> m;  // num : id
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (m.count(num)) continue;
            m[num] = i;
            if (m.count(num-1)) link(i, m[num-1]);
            if (m.count(num+1)) link(i, m[num+1]);
        }
        return *max_element(count.begin(), count.end());
    }
    int find(int x) {
        if (x != root[x]) root[x] = find(root[x]);
        return root[x];
    }
    void link(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            root[ry] = rx;
            count[rx] += count[ry];
        }
    }
};


int main() {
    Solution s;
    vector<int> nums = {100, 200, 1, 10, 2, 4, 3};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}

