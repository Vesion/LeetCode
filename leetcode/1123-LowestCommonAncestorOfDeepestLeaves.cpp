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

// straight forward, three passes
class Solution0 {
public:
    int d = 0;
    vector<TreeNode*> leaves;

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return root;
        depth(root, 0);
        leaf(root, 0);
        if (leaves.size() == 1) return leaves.back();
        TreeNode* res = nullptr;
        for (int i = 1; i < leaves.size(); ++i) {
            if (!res) res = lca(root, leaves[i-1], leaves[i]);
            else res = lca(root, res, leaves[i]);
        }
        return res;
    }
    // get the deepest depth
    void depth(TreeNode* root, int l) {
        if (!root) return;
        d = max(d, ++l);
        depth(root->left, l); depth(root->right, l);
    }
    // find all deepest leaves
    void leaf(TreeNode* root, int l) {
        if (!root) return;
        if (++l == d) leaves.push_back(root);
        leaf(root->left, l); leaf(root->right, l);
    }
    TreeNode* lca(TreeNode* root, TreeNode* a, TreeNode* b) {
        if (root == a || root == b || !root) return root;
        TreeNode* left = lca(root->left, a, b);
        TreeNode* right = lca(root->right, a, b);
        if (left && right) return root;
        return left ? left : right;
    }
};


// one pass
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
    // return {lca of deepest leaves, deepest depth}
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (!root) return {root, 0};
        auto [llca, ldepth] = dfs(root->left);
        auto [rlca, rdepth] = dfs(root->right);
        if (ldepth > rdepth) return {llca, ldepth+1};
        if (rdepth > ldepth) return {rlca, rdepth+1};
        return {root, ldepth+1};
    }
};


// one pass
class Solution2 {
public:
    TreeNode* res;
    int deepest = 0;

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
    // return the deepest depth of the tree
    // postorder, firstly get the deepest depth of the whole tree
    // then check lca based on depth of left/right subtree
    int dfs(TreeNode* root, int depth) {
        deepest = max(deepest, depth);
        if (!root) return depth;
        int left = dfs(root->left, depth+1);
        int right = dfs(root->right, depth+1);
        if (left == deepest && right == deepest) res = root;
        return max(left, right);
    }
};


int main() {
}