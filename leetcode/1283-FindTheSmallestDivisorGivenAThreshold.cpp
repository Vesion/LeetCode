#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lower = 1, upper = 1e6+1;
        while (lower < upper) {
            int mid = lower + (upper-lower)/2;
            if (can(nums, mid, threshold)) upper = mid;
            else lower = mid+1;
        }
        return lower;
    }

    bool can(const vector<int>& nums, int d, int t) {
        int sum = 0;
        for (int num : nums) {
            sum += ceil(float(num)/d);
            if (sum > t) return false;
        }
        return true;
    }
};

int main() {

}