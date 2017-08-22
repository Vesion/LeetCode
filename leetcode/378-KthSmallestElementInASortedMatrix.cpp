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
        if (matrix.empty()) return 0;
        int n = matrix.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({matrix[0][0], 0});
        int res = 0;
        while (!pq.empty() && k--) {
            res = pq.top().first;
            int i = pq.top().second/n, j = pq.top().second%n;
            pq.pop();
            if (j+1 < n) pq.push({matrix[i][j+1], i*n+(j+1)});
            if (j == 0 && i+1 < n) pq.push({matrix[i+1][j], (i+1)*n+j});
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

