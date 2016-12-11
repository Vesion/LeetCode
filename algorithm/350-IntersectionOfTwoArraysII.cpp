#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

// Solution 1 : unordered_multiset (or unordered_map to count)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> s(nums1.begin(), nums1.end());
        vector<int> res;
        for (int num : nums2) {
            auto it = s.find(num);
            if (it != s.end()) {
                res.push_back(num);
                s.erase(it);
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> n1 = {1,1,2,2,3,3,3};
    vector<int> n2 = {3,3,2,1,1,1};
    auto r = s.intersect(n1, n2);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}

