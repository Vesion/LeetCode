#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Solution 0 : naive dp, O(n^3), TLE
class Solution_0 {
public:
    bool canCross(vector<int>& stones) {
        if (stones.empty()) return false;
        int n = stones.size();
        if (n == 1) return true;
        if (stones[1] != 1) return false;

        vector<unordered_set<int>> dp(n); // dp[i] records the all steps to reach i
        dp[1].insert(1);
        for (int i = 2; i < n; ++i) {
            for (int j = i-1; j > 0; --j) {
                int dist = stones[i]-stones[j];
                for (int step : dp[j]) {
                    if (abs(dist-step) <= 1) dp[i].insert(dist);
                }
            }
        }
        return !dp[n-1].empty();
    }
};


// dp[i][k] = whether can make a k jump when at position i
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n+1, false));
        dp[0][1] = true;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int jump = stones[i] - stones[j];
                if (jump > n || !dp[j][jump]) continue;
                dp[i][jump] = true;
                if (jump-1 >= 0) dp[i][jump-1] = true;
                if (jump+1 <= n) dp[i][jump+1] = true;
                if (i == n-1) return true;
            }
        }
        return false;
    }
};


// Solution 1 : dp, generate positions
// For solution 0, it cost large time (O(n^2)) to find all steps to reach one position, so finally it's O(n^3).
// This solution extends all posssible positions from current position in O(n), so finally it's O(n^2).
class Solution1 {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;
        dp[0].insert(0);
        for (int pos : stones) {
            for (int step : dp[pos]) {
                if (step-1 > 0) // Note that the frog can only jump in the forward direction.
                    dp[pos + step-1].insert(step-1);
                dp[pos + step].insert(step);
                dp[pos + step+1].insert(step+1);
            }
        }
        return !dp[stones.back()].empty();
    }
};


// Solution 2 : dfs + memo, skillful memo
// trivial dfs gets TLE, so we need to combine current position and current step into a 'key' to memo current state
//
// Thare are at most 1100 stones,
//      and start step is 1, so the largest step(k) is 1100;
//      the largest position index is 1100, so we only need 11 bits (2^11 == 2048 > 1100).
// So, key is (k << 11) | pos
class Solution2 {
public:
    unordered_map<int, bool> memo;

    bool canCross(vector<int>& stones) {
        return dfs(stones, 0, 0);
    }

    bool dfs(vector<int>& stones, int pos, int k) {
        int key = (k << 11) | pos;
        if (memo.count(key)) return memo[key];
        if (pos == (int)stones.size()-1) return true;
        for (int i = pos+1; i < (int)stones.size(); ++i) {
            int dist = stones[i]-stones[pos];
            if (dist < k-1) continue;
            if (dist > k+1) return memo[key] = false;
            if (dfs(stones, i, dist)) return memo[key] = true;
        }
        return false;
    }
};



int main() {
    Solution s;
    vector<int> st = {0,1,3,6,10,15,16,21};
    //vector<int> st = {0,1,2,3,4,8,9,11};

    cout << s.canCross(st) << endl;

    return 0;
}

