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
    int res = 0;
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return res;
    }

    pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0,0};
        auto [linc, ldec] = dfs(root->left);
        auto [rinc, rdec] = dfs(root->right);
        if (root->left && root->val == root->left->val+1) ++linc; else linc = 1;
        if (root->left && root->val == root->left->val-1) ++ldec; else ldec = 1;
        if (root->right && root->val == root->right->val+1) ++rinc; else rinc = 1;
        if (root->right && root->val == root->right->val-1) ++rdec; else rdec = 1;
        res = max(res, max(linc+rdec-1, ldec+rinc-1));
        return {max(linc, rinc), max(ldec, rdec)};
    }
};


int main() {
    return 0;
}
