#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> 
#include <string>
using namespace std;

// Stome Game is a classical interval dp problem.
//
// Problem:
//      Given n piles of stones, we can merge two adjacent piles each time, its cost is the sum of this two piles of stones. 
//      What is the minimum cost after merging all piles into one?


// Solution 1 : interval dp
// similar to 'matrix chain multiplication'
//      dp[i][j] = min { dp[i][k] + dp[k+1][j] | i <= k < j } + sum[i][j], sum[i][j] is total sum from pile i to pile j
// O(N^3) time, O(N^2) space
int stone_game_dp(vector<int>& stones) {
    int n = stones.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> sum(n+1, 0);
    partial_sum(stones.begin(), stones.end(), sum.begin()+1);
    for (int l = 1; l < n; ++l) {
        for (int i = 0; i < n-l; ++i) {
            int j = i + l;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j+1]-sum[i]);
            }
        }
    }
    return dp[0][n-1];
}


// Solution 2 : interval dp + quadrilateral inequality (四边形不等式优化)
// http://blog.csdn.net/a2520123/article/details/7835355
int stone_game_qi(vector<int>& stones) {
    int n = stones.size();
    vector<vector<int>> dp(n+2, vector<int>(n+2 ,0));
    vector<vector<int>> p(n+2, vector<int>(n+2, 0));
    vector<int> sum(n+2, 0);

    for (int i = 1; i <= n; ++i) sum[i] = sum[i-1] + stones[i-1];
    for (int i=1; i<=n; i++)  p[i][i] = i;  
    for (int len=1; len<n; len++)  {  
        for(int i=1; i+len<=n; i++)  {  
            int end = i+len;  
            int tmp = INT_MAX;  
            int k = 0;  
            for(int j=p[i][end-1]; j<=p[i+1][end]; j++)  {  
                if(dp[i][j] + dp[j+1][end] + sum[end] - sum[i-1] < tmp)  {  
                    tmp = dp[i][j] + dp[j+1][end] + sum[end] - sum[i-1];  
                    k = j;  
                }  
            }  
            dp[i][end] = tmp;  
            p[i][end] = k;  
        }  
    }  
    return dp[1][n];  
}


// Solution 3 : Garsia-Wachs Algorithm, hard!
// http://poj.org/problem?id=1738
// http://www.tuicool.com/articles/MnI7fq
const int MAX = 50082;
int s[MAX];
int n, num;
int res;

void combine(int k) {
    // merge
    int tmp = s[k-1] + s[k];
    res += tmp;
    // move s[k+1...] to s[k...]
    for (int i = k; i < num-1; ++i) s[i] = s[i+1];
    num--;
    // insert
    int j;
    for (j = k-1; j > 0 && s[j-1] < tmp; --j) s[j] = s[j-1];
    s[j] = tmp;
    // backtracking
    while (j >= 2 && s[j] >= s[j-2]) {
        int d = num - j;
        combine(j-1);
        j = num - d;
    }
}

int stone_game_gw() {
    while (cin >> n && n > 0) {
        for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
        num = 1;
        res = 0;
        for (int i = 1; i < n; ++i) {
            s[num++] = s[i];
            while (num >= 3 && s[num-3] <= s[num-1]) combine(num-2);
        }
        while (num > 1) combine(num-1);
        cout << res << endl;
    }
    return 0;
}


int main() {
    vector<int> stones = {1, 1, 1, 1};    
    cout << stone_game_dp(stones) <<endl;;
    cout << stone_game_qi(stones) <<endl;;
    return 0;
}
