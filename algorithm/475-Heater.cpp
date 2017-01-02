#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

// Solution 1 : binary search the radius in all possible values
class Solution_1 {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int left = 0, right = max(houses.back()-houses.front(), max(abs(heaters.front()-houses.back()), abs(heaters.back()-houses.front())));
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (cover(houses, heaters, mid)) right = mid-1;
            else left = mid+1;
        }
        return left;
    }

    bool cover(vector<int>& houses, vector<int>& heaters, int r) {
        int i = 0, j = 0;
        int m = houses.size(), n = heaters.size();
        while (i < m && j < n) {
            if (houses[i] < heaters[j]-r) return false;
            if (houses[i] > heaters[j]+r) ++j;
            else ++i;
        }
        return i == m;
    }
};


// Solution 2 : binary search each house's position, faster
//      1. For each house, find its position between those heaters (thus we need the heaters array to be sorted).
//      2. Calculate the distances between this house and left heater and right heater, get a MIN value of those two values. Corner cases are there is no left or right heater.
//      3. Get MAX value among distances in step 2. It's the answer.
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for (int h : houses) {
            auto right = lower_bound(heaters.begin(), heaters.end(), h);
            int r = 0;
            if (right == heaters.end()) r = h - heaters.back();
            else if (right == heaters.begin()) r = heaters.front() - h;
            else r = min(*right-h, h-*(right-1));
            res = max(res, r);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> houses = {1,2,3,4};
    vector<int> heaters = {1,4};
    cout << s.findRadius(houses, heaters) << endl;;
    return 0;
}
