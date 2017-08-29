#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;


// Similar to 378-KthSmallestElementInASortedMatrix

// Solution 1 : heap, O(klogk), TLE due to k in [1, m*n]
class Solution_1 {
public:
  int findKthNumber(int m, int n, int k) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({1, 0});
    int res = 0;
    while (!pq.empty() && k--) {
      auto p = pq.top(); pq.pop();
      res = p.first;
      int i = p.second/n, j = p.second%n;
      if (j+1 < n) pq.push({(i+1)*(j+2), i*n+(j+1)});
      if (j == 0 && i+1 < m) pq.push({(i+2)*(j+1), (i+1)*n+j});
    }
    return res;
  }
};


// Solution 2 : binary search, O(m*logN), N is search range from smallest number to largest one, m is number of rows
class Solution {
public:
  int findKthNumber(int m, int n, int k) {
    int left = 1, right = m*n;
    while (left <= right) {
        int mid = left + (right-left)/2;
        int count = 0, j = n-1;
        for (int i = 0; i < m; ++i) {
            while (j >= 0 && (i+1)*(j+1) > mid) --j;
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
  cout << s.findKthNumber(3, 3, 5) << endl;
  return 0;
}
