#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Solution 1 : heap, O(klogk), same with 373-FIndKPairsWithSmallestSums
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        auto comp = [&](const pair<int,int>& p1, const pair<int,int>& p2) { 
            return matrix[p1.first][p1.second] > matrix[p2.first][p2.second]; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> q(comp);
        q.push({0, 0});
        int res;
        while (k-- && !q.empty()) {
            auto t = q.top(); q.pop();
            res = matrix[t.first][t.second];
            if (t.second+1 < n)
                q.push({t.first, t.second+1});
            if (t.second == 0 && t.first+1 < m)
                q.push({t.first+1, t.second});
        }
        return res;
    }
};


// Solution 2 : binary search, O(logN * n), N is search range from smallest number to largest one, n is number of rows
class Solution_2 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];
        while (left <= right) {
            int mid = left + (right-left)/2;
            int count = 0, j = n-1;
            for (int i = 0; i < n; ++i) {
                while (j >= 0 && matrix[i][j] > mid) --j;
                count += j+1;
            }
            if (count < k) left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};


int main() {
    Solution s;
    return 0;
}

