#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
using namespace std;

// Solution 1 : binary search, O(nlogm), TLE
// Sort heaters, for each house, binary search the right closest heater and left closest heater
class Solution_1 {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for (int& house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house); // find the right closest heater
            if (it == heaters.end()) res = max(res, house-heaters.back()); // corner case 1 : no heater in its right
            else if (it == heaters.begin()) res = max(res, heaters.front()-house); // corner case 2 : no heater in its left
            else res = max(res, min(*it-house, house-*(it-1)));
        }
        return res;
    }
};


// Solution 2 : sort and compare one by one, O(max(nlogn, mlogn))
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int m = heaters.size();
        int j = 0;
        int res = 0;
        for (int& house : houses) {
            while (j < m && heaters[j] < house) ++j;
            if (j == m) res = max(res, house-heaters.back());
            else if (j == 0) res = max(res, heaters.front()-house);
            else res = max(res, min(heaters[j]-house, house-heaters[j-1]));
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
