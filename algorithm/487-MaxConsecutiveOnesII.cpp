#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Solution 1 : sliding window
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, j = 0;
        int c = 0;
        int k = 1; // we can flip 0 at most k times
        int res = 0;
        while (j < (int)nums.size()) {
            if (nums[j++] == 0) ++c;
            while (c > k) {
                if (nums[i++] == 0) --c;
            }
            res = max(res, j-i);
        }
        return res;
    }
};

// solution above is just for the plain array, but in the follow-up, we will recieve data stream
// thus we cannot store all numbers in memory, so we need to record k most recent indexes of zeroes
class Solution_for_followup {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i = 0, j = 0;
        int c = 0;
        int k = 1; // we can flip 0 at most k times
        int res = 0;
        queue<int> zeroes; // we use a queue to maintain k indexes of zeroes
        while (j < (int)nums.size()) {
            if (nums[j++] == 0) {
                ++c;
                zeroes.push(j);
            }
            if (c > k) {
                i = zeroes.front(); zeroes.pop();
                --c;
            }
            res = max(res, j-i);
        }
        return res;
    }
};


int main() {
    return 0;
}
