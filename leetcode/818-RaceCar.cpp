#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <queue>
#include <cassert>
using namespace std;


// BFS
class Solution0 {
public:
    // A status is defined by both pos and speed
    struct S {
        int pos, speed;
    };
    struct Shash {
        size_t operator()(const S& s) const {
            return hash<int>()(s.pos) ^ hash<int>()(s.speed);
        }
    };
    struct Sequal {
        bool operator()(const S& s1, const S& s2) const {
            return s1.pos == s2.pos && s1.speed == s2.speed;
        }
    };
    int racecar(int target) {
        queue<S> q;
        q.push({0, 1});
        int res = 0;
        unordered_set<S, Shash, Sequal> m(8, Shash(), Sequal());
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto t = q.front(); q.pop();
                if (t.pos == target) return res;

                S ns1({t.pos+t.speed, t.speed*2});
                if (ns1.pos > 0 && ns1.pos < target*2 && !m.count(ns1)) m.insert(ns1), q.push(ns1);

                S ns2({t.pos, t.speed > 0 ? -1 : 1});
                if (ns2.pos > 0 && ns2.pos < target*2 && !m.count(ns2)) m.insert(ns2), q.push(ns2);
            }
            ++res;
        }
        return -1;
    }
};


// DP
// https://leetcode.com/problems/race-car/discuss/123834/JavaC%2B%2BPython-DP-solution
// https://leetcode.com/problems/race-car/discuss/227415/Figures-to-make-the-DP-solution-more-straightforward
class Solution {
public:
    // dp[i] = the minimum steps to reach position i starting from position 0,
    // with initial speed of 1, and its direction pointing towards position i.
    vector<int> dp;

    int racecar(int target) {
        assert(target > 0);
        dp = vector<int>(target+1, 0);
        return dfs(target);
    }

    int dfs(int i) {
        if (dp[i]) return dp[i];
        // n is the length of p in binary format
        int n = floor(log2(i)) + 1;

        if (i == (1<<n)-1) {
            // if i = 2^n-1 = 1 + 2 + 4 + ... + 2^(n-1)
            // we can reach i with exact n steps
            dp[i] = n;
        } else {
            // else we try two strategies to reach i, get min of them:
            // 1. Use n A to arrive at 2^n-1 first, then use R to change the direction
            dp[i] =  n + 1 + dfs((1<<n)-1 - i);
            // 2. Use n-1 A to arrive at 2^(n-1)-1 first, then R to change the direction,
            //    use m A to go backward, then use R to change the direction again
            for (int m = 0; m < n-1; ++m) {
                int forward = (1<<(n-1))-1;
                int backward = (1<<m)-1;
                int remain = i - (forward - backward);
                dp[i] = min(dp[i], dfs(remain) + (n-1)+1 + m+1);
            }
        }
        return dp[i];
    }
};

int main() {
    Solution s;
    cout << s.racecar(1) << endl;
}