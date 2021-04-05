#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// binary search
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 1;
        for (int w : weights) {
            left = max(left, w);
            right += w;
        }
        while (left < right) {
            int mid = left + (right-left)/2;
            if (can(weights, mid, days)) right = mid;
            else left = mid+1;
        }
        return left;
    }

    int can(const vector<int>& weights, int capacity, int days) {
        int d = 1, sum = 0;
        for (int w : weights) {
            if (sum + w <= capacity) sum += w;
            else {
                sum = w;
                ++d;
            }
            if (d > days) return false;
        }
        return true;
    }
};

int main() {
}
