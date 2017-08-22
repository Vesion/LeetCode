#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

// Solution 1 : hash table
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


// Solution 2 : sort
class Solution_2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                if (res.empty() || nums1[i] != res.back()) res.push_back(nums1[i]);
                ++i; ++j;
            }
            else if (nums1[i] < nums2[j]) ++i;
            else ++j;
        }
        return res;
    }
};


int main() {
    return 0;
}
