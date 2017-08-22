#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;


inline bool isValid(vector<vector<int>> &nums) {
    for (int i = 0; i < 3; ++i) {
        int sum = 0;
        for (int j = 0; j < 3; ++j)
            sum += nums[i][j];
        if (sum != 15) return false;
    }
    for (int i = 0; i < 3; ++i) {
        int sum = 0;
        for (int j = 0; j < 3; ++j)
            sum += nums[j][i];
        if (sum != 15) return false;
    }
    if (nums[0][0] + nums[1][1] + nums[2][2] != 15) return false;
    if (nums[0][2] + nums[1][1] + nums[2][0] != 15) return false;
    return true;
}

// find all valid results, rather than one
void dfs(vector<vector<int>>& nums, int i, int j, vector<bool>& used, vector<vector<vector<int>>>& results) {
    if (j == 3) { j = 0; ++i; } // next line
    if (i >= 3) {
        if (isValid(nums)) results.push_back(nums);
        return;
    }
    if (nums[i][j]) // if 0, next grid
        dfs(nums, i, j+1, used, results);
    else 
        for (int n = 1; n <= 9; ++n) { // choose a unused number
            if (used[n]) continue;
            nums[i][j] = n; used[n] = true;
            dfs(nums, i, j+1, used, results); // fill it, next grid
            nums[i][j] = 0; used[n] = false;
        }
}

int main() {
    ifstream cin("in.txt");
    vector<vector<int>> nums(3, vector<int>(3, 0));
    vector<bool> used(10, false);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> nums[i][j];
            if (nums[i][j]) used[nums[i][j]] = true;
        }
    }
    vector<vector<vector<int>>> results;
    dfs(nums, 0, 0, used, results);

    if (results.size() == 1) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                cout << results[0][i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "Too Many" << endl;
    return 0;
}
