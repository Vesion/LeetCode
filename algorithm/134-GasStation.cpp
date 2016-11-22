#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int tank = 0, total = 0;
        for (int i = 0; i < (int)gas.size(); ++i) {
            tank += gas[i] - cost[i];
            if (tank < 0) { // if cannot reach i from start, then any station between [start, i] cannot reach i
                start = i+1;
                tank = 0;
            }
            total += gas[i] - cost[i];
        }
        return total >= 0 ? start : -1; // can reach n-1 from start, check the total needed gas
    }
};

int main() {
    Solution s;
    vector<int> gas = {2, 3};
    vector<int> cost = {3, 4};
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}

