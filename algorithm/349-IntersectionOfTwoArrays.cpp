#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

// Solution 1 : sort
class Solution_1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        vector<int> res;
        while (i < n1 && j < n2) {
            if (i > 0 && nums1[i] == nums1[i-1]) { ++i; continue; }
            if (j > 0 && nums2[j] == nums2[j-1]) { ++j; continue; }
            if (nums1[i] < nums2[j]) ++i;
            else if (nums1[i] > nums2[j]) ++j;
            else {
                res.push_back(nums1[i]);
                ++i, ++j;
            }
        }
        return res;
    }
};


// Solution 2 : unordered_set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for (int num : nums2) {
            if (s.count(num)) {
                res.push_back(num);
                s.erase(num);
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> n1 = {1,1,3,3,3,1,1,1,2};
    vector<int> n2 = {2,2,2,2,3};
    auto r = s.intersection(n1, n2);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}

