#include <iostream>
#include <vector>
using namespace std;

// Solution 1 : similar to LIS, O(n) time
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> res;
        for (int num : nums) {
            if (res.empty() || num > res.back()) res.push_back(num);
            else {
                for (int i = 0; i < (int)res.size(); ++i)
                    if (res[i] >= num) { res[i] = num; break; }
            }
            if (res.size() == 3) return true;
        }
        return false;
    }
};


// Solution 2 : same idea, but more concise
class Solution_2 {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, middle = INT_MAX;
        for (auto & num : nums) {
            if (num <= small) small = num;
            else if (num <= middle) middle = num;
            else return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
