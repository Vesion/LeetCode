#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <climits> 
#include <cmath> 
using namespace std;

// http://www.geeksforgeeks.org/range-minimum-query-for-static-array/

// Problem:
//      RMQ(Range-Minimum-Query) problem given an array nums, and a query is a range [l, r], we have to answer the minimum value of from nums[l] to nums[r].
//      The array is of size N, and there are Q queries.
//
// Solutions:
//      For each query:
//      1. Brute-force: O(N) time, O(1) space
//      2. Segment Tree:
//              Preprocessing: O(N) time, O(N) space
//              Query: O(logN) time
//      3. Square Root Decomposition: 
//              Preprocessing: O(sqrt(N)*sqrt(N)) = O(N) time, O(sqrt(N)) space
//              Query: O(sqrt(N))
//      4. Sparse Table (ST):
//              Preprocessing: O(NlogN) time, O(NlogN) space
//              Query: O(1)


const int MAXN = 100;
int nums[MAXN];
int dp[MAXN][MAXN]; // dp[i][j] = the minimum value of nums[i, i+(1<<j)), length of pow(2, j)
int N, Q;

void preprocess() {
    for (int i = 0; i < N; ++i) dp[i][0] = nums[i];
    for (int j = 1; (1<<j) <= N; ++j) {
        for (int i = 0; (i+(1<<j)-1) < N; ++i) {
            dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l, int r) {
    int p = (int)log2(r-l+1);
    return min(dp[l][p], dp[r-(1<<p)+1][p]);
}


int main() {
    cin >> N >> Q;    
    for (int i = 0; i < N; ++i) cin >> nums[i];
    preprocess();
    for (int i = 0; i < Q; ++i) {
        int l, r; cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}
