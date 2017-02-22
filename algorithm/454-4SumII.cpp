#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// Solution 1 : hash table, O(n^2)
class Solution_1 {
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


// Solution 2 : two pointers, O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        int n2 = n*n;
        vector<int> ab(n2), cd(n2);
        for (int i = 0; i < n; ++i) { for (int j = 0; j < n; ++j) { ab[i*n+j] = A[i] + B[j]; cd[i*n+j] = C[i] + D[j]; } }
        sort(ab.begin(), ab.end());
        sort(cd.begin(), cd.end());
        int res = 0;
        int i = 0, j = n2-1;
        while (i < n2 && j >= 0) {
            if (ab[i] + cd[j] > 0) --j;
            else if (ab[i] + cd[j] < 0) ++i;
            else {
                int ca = 1, cb = 1;
                while (++i < n2 && ab[i] == ab[i-1]) ++ca;
                while (--j >= 0 && cd[j] == cd[j+1]) ++cb;
                res += ca * cb;
            }
        }
        return res;
    }
};


int main() {
    return 0;
}

