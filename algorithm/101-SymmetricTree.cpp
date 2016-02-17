#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution 1 : recursively, O(lgn) space
bool isSymmetric_re(TreeNode* left, TreeNode* right) {
    return (!left && !right) 
        || (left && right && left->val == right->val 
                && isSymmetric_re(left->left, right->right) 
                && isSymmetric_re(left->right, right->left));
}
bool isSymmetric_re(TreeNode* root) {
    return (!root || isSymmetric_re(root->left, root->right));
}


// Solution 2 : iteratively
bool isSymmetric_it(TreeNode* root) {
    if (!root) return true;
    stack<TreeNode*> s;
    s.push(root->left);
    s.push(root->right);
    while (!s.empty()) {
        TreeNode* p = s.top(); s.pop();
        TreeNode* q = s.top(); s.pop();
        if (!p && !q) continue;
        if (!p || !q) return false; 
        if (p->val != q->val) return false;
        s.push(p->left); s.push(q->right);
        s.push(p->right); s.push(q->left);
    }
    return true;
}

int main() {
    return 0;
}
