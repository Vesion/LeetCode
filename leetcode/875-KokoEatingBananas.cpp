#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// binary search
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9+5;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (can(piles, mid, h)) right = mid;
            else left = mid+1;
        }
        return left;
    }

    bool can(const vector<int>& piles, int speed, int h) {
        for (int p : piles) {
            h -= (p-1)/speed + 1;
            if (h < 0) return false;
        }
        return true;
    }
};


int main() {
}
