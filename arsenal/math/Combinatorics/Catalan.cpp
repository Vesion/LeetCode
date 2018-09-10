#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Catalan numbers are a sequence of natural numbers that occurs in many combinatorial mathematics.
// Many recursively-defined problems are about catalan numbers, i.e.
//      1) Count the number of expressions containing n pairs of parentheses which are correctly matched.
//      2) Count the number of possible Binary Search Trees with n keys.
//
// Catalan numbers satisfy the following recursive formula:
//      C[0] = 1
//      C[n] = Sum{ C[i]*C[n-i-1], i from 0 to n-1 }
// Use Binomial Coefficient:
//      C[n] = C(2n, n) / (n+1)


// Solution 1 : top-down
int catalan(int n) {
    if (n <= 1) return 1;
    int result = 0;
    for (int i = 0; i < n; ++i)
        result += catalan(i) * catalan(n-i-1);
    return result;
}


// Solution 2 : bottom-up
int catalan_dp(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}


// A concrete application, generate all BSTs of length n
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

vector<TreeNode*> dfs(int start, int end) {
    if (start > end) return {NULL};
    vector<TreeNode*> res;
    for (int i = start; i <= end; ++i) {
        for (TreeNode* left : dfs(start, i-1)) {
            for (TreeNode* right : dfs(i+1, end)) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    return dfs(1, n);
}


int main() {
    for (int i = 0; i <= 10; ++i)
        cout << catalan(i) << " " << catalan_dp(i) <<endl;;
    return 0;
}
