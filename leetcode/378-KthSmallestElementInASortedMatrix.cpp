#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Solution 1 : heap, O(klogk)
// consider the matrix as a directed garph, start from [0,0], get a k-length path with minimum cost
// similar with 373-FindKPairsWithSmallestSums
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        using S = tuple<int,int,int>;
        priority_queue<S, vector<S>, greater<S>> pq;
        pq.push({matrix[0][0], 0, 0});
        int res = 0;
        while (!pq.empty() && k--) {
            auto [t, i, j] = pq.top(); pq.pop();
            res = t;
            if (j+1 < n) pq.push({matrix[i][j+1], i, j+1});
            // Note we extend i only if j is 0, think why?
            // because matrix[i][j] can only be extened by matrix[i][j-1] if j > 0
            if (j == 0 && i+1 < n) pq.push({matrix[i+1][j], i+1, j});
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

