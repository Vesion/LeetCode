#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// sort jobs with end time
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());

        // dp[i] = max profit after processing first i jobs
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        for (int i = 1; i < n; ++i) {
            int profit = jobs[i][2];
            // binary search the job whose end time <= current start time
            auto it = upper_bound(jobs.begin(), jobs.end(), jobs[i][1],
                [](const int& start, const vector<int>& job) {
                   return start < job[0];
                });
            if (it != jobs.begin()) {
                int j = prev(it)-jobs.begin();
                profit += dp[j];
            }
            // for job i, we can choose schedule it or not schedule it
            dp[i] = max(dp[i-1], profit);
        }
        return dp[n-1];
    }
};

int main() {
}
