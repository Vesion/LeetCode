#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

// This is a NPC problem
//
// https://leetcode.com/problems/optimal-account-balancing/discuss/95355/Concise-9ms-DFS-solution-(detailed-explanation)
class Solution {
public:
    vector<int> debt;

    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int,int> m;
        for (const auto& t : transactions) {
            m[t[0]] -= t[2];
            m[t[1]] += t[2];
        }
        for (const auto& p : m) {
            if (p.second)  // do not need to consider persons whose debt is 0
                debt.push_back(p.second);
        }
        return dfs(0);
    }

    int dfs(int s) {
        // skip already clear debts
        while (s < debt.size() && debt[s] == 0) ++s;
        int res = INT_MAX;
        for (int i = s+1; i < debt.size(); ++i) {
            if (debt[i] * debt[s] < 0) {
                debt[i] += debt[s];
                res = min(res, dfs(s+1)+1);
                debt[i] -= debt[s];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> t = { { 0,1,1 }, { 2,3,2 }, { 4,5,3 }, { 6,7,4 }, { 8,9,5 }, { 10,11,6 }, { 12,13,7 }, { 14,15,2 }, { 14,16,2 }, { 14,17,2 }, { 14,18,2 } };
    cout << s.minTransfers(t) <<endl;
    return 0;
}

