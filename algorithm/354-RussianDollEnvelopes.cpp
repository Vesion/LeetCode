#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set> 
#include <iterator> 
using namespace std;

// Solution 1 : naive dp, O(n^2) time
class Solution_1 {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0;

        int n = envelopes.size();
        vector<int> dp(n, 1);
        int result = 1;

        sort(envelopes.begin(), envelopes.end());

        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second)
                    dp[i] = max(dp[i], dp[j]+1);
            }
            result = max(dp[i], result);
        }
        return result;
    }
};

// Solution 2 : binary search + dp, O(nlogn) time
// similar to LIS O(nlogn) solution, skillful
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if (envelopes.empty()) return 0;

        sort(envelopes.begin(), envelopes.end(),
                [](const pair<int, int>& e1, const pair<int, int>& e2) { 
                    if (e1.first < e2.first) return true; 
                    if (e1.first == e2.first) return e1.second > e2.second;
                    return false;
                }); 
        vector<int> dp;
        for (int i = 0; i < (int)envelopes.size(); ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if (it == dp.end())
                dp.push_back(envelopes[i].second);
            else
                *it = envelopes[i].second;
        }
        return dp.size();
    }
};


int main() {
    Solution s;
    vector<pair<int, int>> e = { {1, 7}, {2, 5} ,{ 4,5 },{ 4,6 },{ 6,7 },{ 2,3 },{ 1,1 } } ;
    cout << s.maxEnvelopes(e) << endl;
    return 0;
}
