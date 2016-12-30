#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// bind 4 arrays pairwise into 2 big arrays
// then search two elements sum to 0 in 2 big arrays respectively, O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        unordered_map<long long, int> sums;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sums[(long long)A[i]+B[j]]++;
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res += sums[-((long long)C[i]+D[j])];
            }
        }
        return res;
    }  
};


int main() {
    Solution s;
    return 0;
}

