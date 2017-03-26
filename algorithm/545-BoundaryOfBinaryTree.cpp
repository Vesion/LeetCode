#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        vector<TreeNode*> left_boundary, right_boundary, leaves;
        if (root->left) getLeftBoundary(root, left_boundary);
        else left_boundary.push_back(root);
        if (root->right) getRightBoundary(root, right_boundary);
        else right_boundary.push_back(root);
        getLeaves(root, leaves);
        unordered_set<TreeNode*> s;
        vector<int> res;
        for (TreeNode* node : left_boundary) {
            res.push_back(node->val);
            s.insert(node);
        }
        for (TreeNode* leaf : leaves) {
            if (!s.count(leaf)) {
                res.push_back(leaf->val);
                s.insert(leaf);
            }
        }
        for (int i = right_boundary.size()-1; i >= 0; --i) {
            if (!s.count(right_boundary[i])) {
                res.push_back(right_boundary[i]->val);
                s.insert(right_boundary[i]);
            }
        }
        return res;
    }

    void getLeftBoundary(TreeNode* root, vector<TreeNode*>& s) {
        if (!root) return;
        s.push_back(root);
        if (root->left) getLeftBoundary(root->left, s);
        else if (root->right) getLeftBoundary(root->right, s);
    }

    void getRightBoundary(TreeNode* root, vector<TreeNode*>& s) {
        if (!root) return;
        s.push_back(root);
        if (root->right) getRightBoundary(root->right, s);
        else if (root->left) getRightBoundary(root->left, s);
    }

    void getLeaves(TreeNode* root, vector<TreeNode*>& s) {
        if (!root) return;
        if (!root->left && !root->right) s.push_back(root);
        getLeaves(root->left, s);
        getLeaves(root->right, s);
    }
};


int main() {
    Solution s;
    return 0;
}
