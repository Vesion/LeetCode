#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Problem 1 : Find a peak in a 1D array
//
// Solution 0 : brute-force, O(n)
//
// Solution 1 : binary search, O(logn)
class Solution_find_peak {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size()-1;
        while (left < right) { // why < rather than <=, try case [1]
            int mid = left + (right-left)/2;
            if (nums[mid] < nums[mid+1]) // if nums[mid] < nums[mid+1], there must be a peak in nums[mid+1,...,right]
                left = mid+1;
            else // if nums[mid] > nums[mid+1], there must be a peak in nums[left,...,mid]
                right = mid;
        }
        return left;
    }
};


// Problem 2 : Find a peak in a 2D array
//
// Solution 0 : brute-force, iterate all cells, O(n^2)
//
// Solution 1 : use the 1D bianry search solution, O(nlogn)
class Solution_find_peak_2D_bs_nlogn {
public:
    int findPeakElement(vector<vector<int>>& matrix) {
        int left = 0, right = matrix.size()-1;
        while (left < right) {
            int mid = left +(right-left)/2;
            if (getMax(matrix[mid]) < getMax(matrix[mid+1]))
                left = mid+1;
            else 
                right = mid;
        }
        return getMax(matrix[left]);
    }

    int getMax(vector<int>& row) {
        return *max_element(row.begin(), row.end());
    }
};

// Solution 2 : divide and conquer, O(nlogn)
class Solution_find_peak_2D_dac_nlogn {
public:
    int findPeakElement(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        return helper(matrix, m, n, n/2);
    }

    int helper(vector<vector<int>>& matrix, int m, int n, int mid) {
        int max_x = INT_MIN, max_i = -1;
        for (int i = 0; i < m; ++i) if (matrix[i][mid] > max_x) max_x = matrix[i][mid], max_i = i;
        if (mid == 0 || mid == n-1) return max_x;

        if (matrix[max_i][mid-1] > max_x) return helper(matrix, m, n, (mid-1)/2);
        else if (matrix[max_i][mid+1] > max_x) return helper(matrix, m, n, (mid+n)/2);
        else return max_x;
    }
};

// Solution 3 : improved divide and conquer, O(m+n)
//

int main() {
    vector<vector<int>> matrix = {
        { 10, 8, 10, 10 },
        { 14, 13, 12, 11 },
        { 15, 9, 11, 21 },
        { 16, 17, 19, 20 } };
    Solution_find_peak_2D_bs_nlogn s2a;
    cout << s2a.findPeakElement(matrix) << endl;

    Solution_find_peak_2D_dac_nlogn s2b;
    cout << s2b.findPeakElement(matrix) << endl;
    return 0;
}
