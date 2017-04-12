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
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        postorder(root, res);
        return res;
    }
    
    pair<int,int> postorder(TreeNode* root, int& res) {
        if (!root) return {0,0};
        auto left = postorder(root->left, res);
        auto right = postorder(root->right, res);
        if (root->left && root->val == root->left->val+1) left.first++; else left.first = 1;
        if (root->left && root->val == root->left->val-1) left.second++; else left.second = 1;
        if (root->right && root->val == root->right->val+1) right.first++; else right.first = 1;
        if (root->right && root->val == root->right->val-1) right.second++; else right.second = 1;
        res = max(res, max(left.first+right.second-1, left.second+right.first-1));
        return {max(left.first, right.first), max(left.second, right.second)};
    }
};


int main() {
    return 0;
}
