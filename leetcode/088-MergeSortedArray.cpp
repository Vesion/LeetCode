#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = nums1.size()-1;
        for (--m, --n; m >= 0 || n >= 0; --k) {
            if (m >= 0 && n >= 0) nums1[k] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
            else if (m >= 0) nums1[k] = nums1[m--];
            else nums1[k] = nums2[n--];
        }
    }
};


int main() {
    return 0;
}
