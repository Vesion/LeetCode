#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
using namespace std;


// Solution 0.1 : naive dp, MLE!
class Solution_01 {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (n < 2 || stones[1] != 1) return false;
        vector<vector<int>> dp(n, vector<int>());
        dp[0].push_back(0);
        dp[1].push_back(1);
        for (int i = 2; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                for (auto& s : dp[j]) {
                    int ds = stones[i] - stones[j];
                    if (s-1 == ds || s == ds || s+1 == ds)
                        dp[i].push_back(ds);
                }
            }
        }
        return !dp[n-1].empty();
    }
};


// Solution 0.2 : dfs, TLE
class Solution_02 {
public:
    bool dfs(vector<int>& stones, int pos, int k) {
        for (int i = pos+1; i < (int)stones.size(); ++i) {
            int gap = stones[i] - stones[pos];
            if (gap < k-1) continue;
            if (gap > k+1) return false;
            if (dfs(stones, i, gap)) return true;
        }
        return pos == (int)stones.size()-1;
    }

    bool canCross(vector<int>& stones) {
        return dfs(stones, 0, 0);
    }
};


// Solution 1 : dp + hashmap (enumerate)
class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp = {{0, {0}}};
        for (auto& pos : stones) {
            for (auto it = dp[pos].begin(); it != dp[pos].end(); ++it) {
                dp[pos + *it-1].insert(*it-1);
                dp[pos + *it].insert(*it);
                dp[pos + *it+1].insert(*it+1);
            }
        }
        return !dp[stones.back()].empty();
    }
};



int main() {
    //vector<int> st = { 0,1,3,5,6,8,12,17 };
    vector<int> st = { 0,1,2,3,4,8,9,11 };
    Solution s;
    cout << s.canCross(st) << endl;
    return 0;
}
