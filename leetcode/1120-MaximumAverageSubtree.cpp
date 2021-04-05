#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};


class Solution {
public:
    double res = -1;
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }

    pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        auto [lc, ls] = dfs(root->left);
        auto [rc, rs] = dfs(root->right);
        int c = lc + rc + 1;
        int s = ls + rs + root->val;
        res = max(res, double(s)/c);
        return {c, s};
    }
};


int main() {
}