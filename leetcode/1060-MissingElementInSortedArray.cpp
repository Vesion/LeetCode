#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Brute-force, O(n)
class Solution0 {
public:
    int missingElement(vector<int>& nums, int k) {
        int prev = nums[0];
        int i = 1, res = 0;
        while (k > 0) {
            if (i == nums.size()) break;
            if (nums[i] > prev+1) {
                if (nums[i]-prev-1 >= k) res = prev + k;
                k -= (nums[i]-prev-1);
            }
            prev = nums[i++];
        }
        if (k > 0) res = nums.back() + k;
        return res;
    }
};

// Binary search, O(logn)
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        const int n = nums.size();
        const int miss = (nums.back() - nums.front() + 1) - n;
        if (miss < k) {
            return nums.back() + (k - miss);
        }
        int l = 0, r = n-1;  // closed range
        while (l < r-1) {  // at least three numbers
            const int m = l + (r-l)/2;
            const int miss = (nums[m]-nums[l]) - (m-l);
            if (miss < k) {
                l = m;
                k -= miss;
            }
            else r = m;
        }
        return nums[l] + k;
    }
};


int main() {
}
