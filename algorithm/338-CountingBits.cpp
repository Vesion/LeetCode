#include <iostream>
#include <vector>
using namespace std;


// DP, O(n)

// Solution 2 : dp, 121ms
class Solution_1 {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);
        for (int i = 1; i <= num; ++i)
            result[i] = result[i&(i-1)] + 1; // drops the lowest set(1) bit
        return result;
    }
};


// Solution 2 v2 : dp, 120ms
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);
        for (int i = 1; i <= num; ++i)
            result[i] = result[i>>1] + (i&1); // drops the lowest(0 or 1) bit
        return result;
    }
};


int main() {
    return 0;
}
