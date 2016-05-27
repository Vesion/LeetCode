#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Solution 1 : use std::set_intersection and std::unique
vector<int> intersection_1(vector<int>& nums1, vector<int>& nums2) {
    vector<int> rv(nums1.size() + nums2.size());
    sort(nums1.begin(), nums1.end()); sort(nums2.begin(), nums2.end());

    auto it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), rv.begin());
    rv.resize(it-rv.begin());

    it = unique(rv.begin(), rv.end());
    rv.resize(it-rv.begin());
    return rv;
}


// Solution 2 : use std::unordered_set (or unordered_map)
vector<int> intersection_2(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> m(nums1.begin(), nums1.end());
    vector<int> result;
    for (auto &n : nums2) {
        if (m.count(n)) {
            result.push_back(n);
            m.erase(n);
        }
    }
    return result;
}


int main() {
    vector<int> nums1 = {1, 2, 2, 3};
    vector<int> nums2 = {5, 4, 3, 2, 2};
    auto result = intersection_2(nums1, nums2);
    for (auto &r :result) cout << r << " "; cout << endl;
    return 0;
}
