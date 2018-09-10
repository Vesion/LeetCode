#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/optimal-division/

class Solution {
public:
    struct Res {
        double maxv, minv;
        string maxs, mins;
        Res(int _maxv, int _minv, string _maxs, string _mins) : maxv(_maxv), minv(_minv), maxs(_maxs), mins(_mins) {}
    };

    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        vector<vector<Res>> memo(n, vector<Res>(n, {-1, -1, "", ""}));
        return dfs(nums, 0, n-1, memo).maxs;
    }

    Res dfs(vector<int>& nums, int start, int end, vector<vector<Res>>& memo) {
        if (start == end) return {nums[start], nums[start], to_string(nums[start]), to_string(nums[start])};
        if (memo[start][end].minv != -1) return memo[start][end];
        Res res(INT_MIN, INT_MAX, "", "");
        for (int i = start; i < end; ++i) {
            Res left = dfs(nums, start, i, memo);
            Res right = dfs(nums, i+1, end, memo);
            double maxv = left.maxv / right.minv;
            double minv = left.minv / right.maxv;
            string maxs = left.maxs + "/" + (i+1 == end ? right.mins : "("+right.mins+")");
            string mins = left.mins + "/" + (i+1 == end ? right.maxs : "("+right.maxs+")");
            if (maxv > res.maxv) res.maxv = maxv, res.maxs = maxs;
            if (minv < res.minv) res.minv = minv, res.mins = mins;
        }
        memo[start][end] = res;
        return res;
    }
};


int main() {
    return 0;
}
