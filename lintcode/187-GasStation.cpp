#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        if (n == 0) return -1;
        int tank = 0, start = 0, total = 0;
        for (int i = 0; i < n; ++i) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i+1;
                tank = 0;
            }
            total += gas[i] - cost[i];
        }
        return total >= 0 ? start : -1;
    }
};

int main() {
    Solution s;
    vector<int> gas = {1, 1, 3, 1}, cost = {2, 2, 1, 1};
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
