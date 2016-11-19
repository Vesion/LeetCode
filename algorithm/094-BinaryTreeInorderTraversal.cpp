#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// Solution 1 : recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }

    void dfs(TreeNode* root, vector<int>& res) {
        if (root) {
            dfs(root->left, res);
            res.push_back(root->val);
            dfs(root->right, res);
        }
    }
};


// Solution 2 : stack
class Solution_2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while (!st.empty() || node) {
            while (node) {
                st.push(node);
                node = node->left;
            }
            node = st.top(); st.pop();
            res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};


int main() {
    Solution s;
    return 0;
}

