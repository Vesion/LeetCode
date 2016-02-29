#include <iostream>
#include <vector>
using namespace std;

// Solution 0 : brute-force, O(n^2), TLE of course!
int canCompleteCircuit_n2(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int result = -1;
    for (int i = 0; i < n; ++i) { // try every station, i
        int j = (i == n-1 ? 0 : i+1); // j is the next station
        int total_gas = gas[i] - cost[i]; // current gas when reach j, maybe negative
        while (j != i && total_gas >= 0) { // if sufficient gas, go to next, until travel around to i or lack of gas
            total_gas += (gas[j] - cost[j]);
            j = (j == n-1 ? 0 : j+1);
        }
        if (j == i && total_gas >= 0) { // find the station which can travel around
            result = i;
            break;
        }
    }
    return result;
}


// Solution 1 : greedy, O(n)
// refer to https://leetcode.com/discuss/4159/share-some-of-my-ideas
// 关键就是两点：
//      1. 如果车从站点i出发不能到达站点j（j是i第一个不能到达的站点），那么从任何位于站点i和j之间的站点出发均不能到达站点j，因为gas和cost值都是非负的，不会积累更多的gas
//      2. 如果所有gas的总和大于cost的总和，则必然存在一个可行解，否则不存在返回-1
//
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start = 0; // the lastest start station
    int tank = 0; // current gas in tank
    int total = 0; // total gas and cost
    for (int i = 0; i < gas.size(); ++i) {
        tank += gas[i] - cost[i];
        if (tank < 0) { // get the first unreachable station
            start = i + 1; // choose i+1 to be the next candidate station
            tank = 0; // restart from i+1, which means clear tank
        }
        total += gas[i] - cost[i]; // accumulate gas and cost, for result
    }
    return (total >= 0 ? start : -1);
}

int main() {
    vector<int> gas = {2, 4};
    vector<int> cost = {3, 4};
    cout << canCompleteCircuit_n2(gas, cost) << endl;
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}
