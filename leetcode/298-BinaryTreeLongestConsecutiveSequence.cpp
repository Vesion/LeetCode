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

// Solution 1 : postorder
class Solution_1 {
public:
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        postorder(root, res);
        return res;
    }
    
    int postorder(TreeNode* root, int& res) {
        if (!root) return 0;
        int left = postorder(root->left, res), right = postorder(root->right, res);
        if (!root->left || root->val != root->left->val-1) left = 1;
        else ++left;
        if (!root->right || root->val != root->right->val-1) right = 1;
        else ++right;
        int len = max(left, right);
        res = max(res, len);
        return len;
    }
};


// Solution 2 :preorder
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        dfs(root, 0, res, 0);
        return res;
    }
    
    void dfs(TreeNode* root, int pre, int& res, int len) {
        if (!root) return;
        if (root->val == pre+1) len++;
        else len = 1;
        res = max(res, len);
        dfs(root->left, root->val, res, len);
        dfs(root->right, root->val, res, len);
    } 
};


int main() {
    return 0;
}
