#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Similar to 349 but here do not need unique

// Solution 1 : use std::set_intersection
vector<int> intersect_1(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result(nums1.size() + nums2.size());
    sort(nums1.begin(), nums1.end()); sort(nums2.begin(), nums2.end());
    auto it = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), result.begin());
    result.resize(it-result.begin());
    return result;
}


// Solution 2 : use std::unordered_map to count
vector<int> intersect_2(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m;
    for (auto &n : nums1) m[n]++;
    vector<int> result;
    for (auto &n : nums2) {
        if (m[n] > 0) {
            result.push_back(n);
            --m[n];
        }
    }
    return result;
}


int main() {
    vector<int> nums1 = {1, 2, 2, 3}; 
    vector<int> nums2 = {6, 2, 2, 3}; 
    //auto r = intersect_1(nums1, nums2);
    auto r = intersect_2(nums1, nums2);
    for (auto &n : r) cout << n << " "; cout << endl;
    return 0;
}
