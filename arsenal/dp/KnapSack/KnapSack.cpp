#include <iostream>
#include <vector>
using namespace std;

// 'Knapsack Problem' is a series of very classical dp problem.
//
// It is a NP-Complete problem:
// http://stackoverflow.com/questions/3907545/how-to-understand-the-knapsack-problem-is-np-complete
//
// It has many applications and variations, such ans 'combination sum', 'coins change' ...
//
//
// Version 1 : Basical 0-1 knapsack
//      Problem: each kind of item has weight and value, and amount is 1, fill in W weight knapsack, ensure maximal values
//      Solution: dp[i][j] = max { dp[i-1][j], dp[i-1][j-w[i]]+v[i] }
//
// Version 1.1 : Require the knapsack is exactly full
//      Problem: the total weight of result is exactly W
//      Solution: init dp[1...W] to INT_MIN
//
//
// Version 2 : Unbounded knapsack
//      Problem: the amount of each kind of item is infinite
//      Solution: 
//              trivial: convert it into 0-1 version: dp[i][j] = max { dp[i-1][j-k*w[i]]+k*v[i] | 0 <= k*w <= W }
//              improvement: dp[i][j] = max { dp[i-1][j], dp[i][j-w[i]]+v[i] }
//
//
// Version 3 : Multiple knapsack
//      Problem: the amount of item i is c[i]
//      Solution: divide each kind of item into several groups whose size if power of 2
//              dp[i][j] = max { dp[i-1][j-k*w[i]]+k*v[i] | 0 <= k <= c[i] }
//
//
// Version 4 : 2D Weight knapsack
//      Problem: each item has two type of weight w1 and w2, the upper limit of each is W1 and W2
//      Solution:
//              dp[i][j][k] = max { dp[i-1][j][k], dp[i-1][j-w1i][k-w2i]+v[i] }
//
//
// Version 5 : Group knapsack
//      Problem: based on 0-1 knapsack, divide all kinds of item into k groups, only one item of each group can be put into knapsack
//      Solution:
//              dp[i][j] means the maximal values of first i groups in j weights
//              dp[i][j] = max { dp[i-1][j], dp[i-1][j-w[t]]+v[t] | item t is in group i }
//
// Version 6 : Generalization knapsack
//      Problem: each kind of item has variable weight and value, when its weight is w, its value is f(w)
//      Solution: based on V4, regard each kind of item as a group, which has all variable weight item
//              So, when ith item's weight is w:
//              dp[i][j] = max { dp[i-1][j], dp[i-1][j-w]+f(w) }



// Version 1 : 0-1
// Basical, 2D array, O(N*W) time, O(N*W) space
int knapsack_01_basic(vector<int>& w, vector<int>& v, int W) {
    if (w.empty() || v.empty()) return 0;
    int N = w.size();
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    for (int i = 1; i <= N; ++i) { 
        for (int j = 0; j <= W; ++j) {
            if (j < w[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j-w[i-1]]+v[i-1], dp[i-1][j]);
        }
    } 
    return dp[N][W];
}

// Version 1 : 0-1
// use 1D scrolling array
int knapsack_01(vector<int>& w, vector<int>& v, int W) {
    if (w.empty() || v.empty()) return 0;
    int N = w.size();
    vector<int> dp(W+1, 0);
    for (int i = 0; i < N; ++i)
        for (int j = W; j >= w[i]; --j)
            dp[j] = max(dp[j-w[i]]+v[i], dp[j]);
    return dp[W];
}


// Version 1.1 : 0-1, exactly fill
int knapsack_01_W(vector<int>& w, vector<int>& v, int W) {
    if (w.empty() || v.empty()) return 0;
    int N = w.size();
    vector<int> dp(W+1, INT_MIN);
    dp[0] = 0;
    for (int i = 0; i < N; ++i)
        for (int j = W; j >= w[i]; --j)
            dp[j] = max(dp[j-w[i]]+v[i], dp[j]);
    return dp[W]; // if < 0, it means it's impossible to exactly fill
}


// Version 2 : unbounded
// O(N*W) time
int knapsack_infinite(vector<int>& w, vector<int>& v, int W) {
    if (w.empty() || v.empty()) return 0;
    int N = w.size();
    vector<int> dp(W+1, 0);
    for (int i = 0; i < N; ++i) { 
        for (int j = w[i]; j <= W; ++j) 
            dp[j] = max(dp[j-w[i]]+v[i], dp[j]);
    } 
    return dp[W];
}


// Version 3 : multiple
// O(W*log(∑c[i]))
int knapsack_multiple(vector<int>& w, vector<int>& v, vector<int>& c, int W) {
    if (w.empty() || v.empty() || c.empty()) return 0;
    int N = w.size();
    vector<int> dp(W+1, 0);

    auto unbounded = [W, &dp](int w, int v) { // Complete version
        for (int i = w; i <= W; ++i)
            dp[i] = max(dp[i], dp[i-w]+v);
    };
    auto zeroOne = [W, &dp](int w, int v) { // ZeroOne version
        for (int i = W; i >= w; --i)
            dp[i] = max(dp[i], dp[i-w]+v);
    };

    for (int i = 0; i < N; ++i) {
        if (w[i]*c[i] > W) {
            unbounded(w[i], v[i]);
        }
        else {
            int k = 1;
            while (k < c[i]) {
                zeroOne(k*w[i], k*v[i]);
                c[i] -= k;
                k *= 2;
            }
            zeroOne(c[i]*w[i], c[i]*v[i]);
        }
    }
    return dp[W];
} 


// Version 4 : 2D weights
int knapsack_2DW(vector<int>& w1, vector<int>& w2, vector<int>& v, int W1, int W2) {
    int n = w1.size();
    vector<vector<int>> dp(W1+1, vector<int>(W2+1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = W1; j >= w1[i]; --j) {
            for (int k = W2; k >= w2[i]; --k) {
                dp[j][k] = max(dp[j][k], dp[j-w1[i]][k-w2[i]]+v[i]);
            }
        }
    }
    return dp[W1][W2];
}


// Version 5 : group
// O(N*W)
int knapsack_group(vector<int>& w, vector<int>& v, vector<vector<int>>& group, int W) {
    vector<int> dp(W+1, 0);
    int N = group.size();
    for (int k = 0; k < N; ++k) {
        for (int j = W; j >= 1; --j) {
            for (int i : group[k]) {
                if (j >= w[i])
                    dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
            }
        }
    }
    return dp[W];
}


// Version 6 : generalization
// similar to Version 5
int knapsack_general(vector<vector<int>>& w, vector<vector<int>>& v, int W) {
    vector<int> dp(W+1, 0);
    int N = w.size();
    for (int k = 0; k < N; ++k) {
        for(int j = W; j >= 1; --j) {
            for (int i = 0; i < (int)w[k].size(); ++i) {
                if (j >= w[k][i]) {
                    dp[j] = max(dp[j], dp[j-w[k][i]]+v[k][i]);
                }
            }
        }
    }
    return dp[W];
}


int main() {
    vector<int> weights = {3,3,3,5,7};
    vector<int> values = {3,3,3,5,7};
    cout << knapsack_01(weights, values, 10) << endl;
    cout << knapsack_01_W(weights, values, 10) << endl;
    cout << knapsack_infinite(weights, values, 10) << endl;
    return 0;
}
