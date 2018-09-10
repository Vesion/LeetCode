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

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// The O(nlogn) solution is trivial


// Solution 1 : recursive postorder, O(n)
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* next = NULL; // the next is the 'next node in preorder traversal'
        postorder(root, next);
    }

    void postorder(TreeNode* cur, TreeNode*& next) {
        if (!cur) return;
        postorder(cur->right, next);
        postorder(cur->left, next);
        cur->right = next;
        cur->left = NULL;
        next = cur;
    }
};


// Solution 2 : preorder, stack, O(n)
class Solution_2 {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* t = st.top(); st.pop();
            if (t->right) st.push(t->right);
            if (t->left) st.push(t->left);
            t->left = NULL;
            if (!st.empty()) t->right = st.top();
            else t->right = NULL;
        }
    }   
};


int main() {
    return 0;
}

