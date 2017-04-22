#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : backtracking + memo, O(n^3)
class Solution {
private:
    struct Res {
        double minv, maxv;
        string mins, maxs;
        Res(double _minv, double _maxv, string _mins, string _maxs) : minv(_minv), maxv(_maxv), mins(_mins), maxs(_maxs) {}
    };
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        vector<vector<Res>> memo(n, vector<Res>(n, {-1, -1, "", ""}));
        return dfs(nums, 0, n-1, memo).maxs;
    } 

    Res dfs(vector<int>& nums, int start, int end, vector<vector<Res>>& memo) {
        if (start == end) return {(double)nums[start], (double)nums[start], to_string(nums[start]), to_string(nums[start])};
        if (memo[start][end].maxv != -1) return memo[start][end];
        Res res(INT_MAX, INT_MIN, "", "");
        for (int i = start; i < end; ++i) {
            Res left = dfs(nums, start, i, memo);
            Res right = dfs(nums, i+1, end, memo);
            double minv = left.minv / right.maxv;
            double maxv = left.maxv / right.minv;
            string mins = left.mins + "/" + (i+1 == end ? right.maxs : "("+right.maxs+")");
            string maxs = left.maxs + "/" + (i+1 == end ? right.mins : "("+right.mins+")");
            if (minv < res.minv) res.minv = minv, res.mins = mins;
            if (maxv > res.maxv) res.maxv = maxv, res.maxs = maxs;
        }
        memo[start][end] = res;
        return res;
    }
};


// Solution 2 : math
class Solution_2 {
public:
    string optimalDivision(vector<int>& nums) {
        string res; 
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            res += to_string(nums[i]) + "/";
            if (n > 2 && i == 0) res += "(";
        }
        res.pop_back();
        return n > 2 ? res+")" : res;
    }
};


int main() {
    Solution s;
    vector<int> nums = {1000, 100, 10, 2};
    cout << s.optimalDivision(nums) << endl;
    return 0;
}
