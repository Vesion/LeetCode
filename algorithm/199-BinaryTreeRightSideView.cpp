#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};


// Solution 1 : preorder traversal, root-right-left, O(1) space
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        preorder(root, 0, res);
        return res;
    }
    
    void preorder(TreeNode* root, int depth, vector<int>& res) {
        if (!root) return;
        if (depth == (int)res.size()) res.push_back(root->val);
        preorder(root->right, depth+1, res);
        preorder(root->left, depth+1, res);
    }
};


// Solution 2 : level traversla, O(n) space
class Solution_2 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            int val;
            while (len--) {
                auto node = q.front(); q.pop();
                val = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(val);
        }
        return result;
    }
};


int main() {
    return 0;
}
