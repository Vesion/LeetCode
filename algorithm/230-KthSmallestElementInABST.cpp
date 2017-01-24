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


// Solution 1 : count number of nodes, O(nlogn)
// If we can modify the node's structure, we can add a 'number of nodes' field, then it will cost O(logn) time.
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        int c = countNodes(root->left);
        if (c+1 < k) return kthSmallest(root->right, k-(c+1));
        if (c+1 > k) return kthSmallest(root->left, k);
        return root->val;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};


// Solution 2.1 : inorder traversal, recursive
class Solution_21 {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        int res = 0;
        inorder(root, k, res);
        return res;
    }

    void inorder(TreeNode* root, int& k, int& res) {
        if (root) {
            inorder(root->left, k, res);
            if (--k == 0) {
                res = root->val;
                return;
            }
            inorder(root->right, k, res);
        }
    }
};


// Solution 2.3 : inorder traversal, iterative
class Solution_22 {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top(); st.pop();
                if (--k == 0) break;
                cur = cur->right;
            }
        }
        return cur->val;
    }
};


int main() {
    return 0;
}

