#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric> 
using namespace std;

// Solution 1 : the most easy-understand one
// https://discuss.leetcode.com/topic/79923/c-16ms-o-n-solution
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        if (machines.empty()) return 0;
        int n = machines.size();
        vector<int> sums(n+1, 0);
        for (int i = 0; i < n; ++i) sums[i+1] = sums[i] + machines[i];
        if (sums[n] % n) return -1;
        int target = sums[n] / n;

        int res = 0;
        for (int i = 0; i < n; ++i) {
            int left = i*target - sums[i];
            int right = (n-i-1)*target - (sums[n]-sums[i+1]);
            if (left > 0 && right > 0)
                res = max(res, abs(left) + abs(right));
            else
                res = max(res, max(abs(left), abs(right)));
        }
        return res;
    }
};


// Solution 2 : dp
class Solution_2 {
public:
    int findMinMoves(vector<int>& machines) {
        if (machines.empty()) return 0;
        int n = machines.size();
        int total = accumulate(machines.begin(), machines.end(), 0);
        if (total % n) return -1;
        int target = total / n;
        
        int res = 0;
        vector<int> moves(n, 0);
        for (int i = 0; i < n-1; ++i) { // we always give/borrow dresses from right adjacent machine
            // if this machine has too many dresses, we give all redudant dresses to its right one
            if (machines[i] > target) {
                moves[i] += machines[i]-target;
                machines[i+1] += machines[i]-target;
                res = max(res, moves[i]);
            }
            // if this machine is lack of dresses, we borrow dresses from its right one
            else {
                moves[i+1] = target-machines[i];
                machines[i+1] -= target-machines[i];
                res = max(res, moves[i+1]);
            }
            machines[i] = target;
        }
        return res;
    }
};


// Solution 3 : math
class Solution_3 {
public:
    int findMinMoves(vector<int>& machines) {
        if (machines.empty()) return 0;
        int n = machines.size();
        int total = accumulate(machines.begin(), machines.end(), 0);
        if (total % n) return -1;
        int target = total / n; 

        int res = 0, count = 0;
        for (int& num : machines) {
            count += num - target;
            res = max(res, max(abs(count), num-target));
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> m = {0, 3, 0};
    cout << s.findMinMoves(m) << endl;
    return 0;
}

