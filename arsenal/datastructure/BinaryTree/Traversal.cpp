#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};


// preorder / inorder / postorder / level order
// recursively + iteratively


// preorder traverse, recursively
class Solution_pre_re {
public:
    void preorder(TreeNode* root) {
        if (root) {
            cout << root->val << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }
};

// preorder traverse, stack
class Solution_pre_it {
public:
    void preorder(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* p = st.top(); st.pop();
            cout << p->val << " ";
            if (p->right) st.push(p->right);
            if (p->left) st.push(p->left);
        }
    }
};


// inorder traverse, recursively
class Solution_in_re {
public:
    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);
            cout << root->val << " ";
            inorder(root->right);
        }
    }
};

// inorder traverse, stack
class Solution_in_it {
public:
    void inorder(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while (!st.empty() || p) {
            if (p) {
                st.push(p);
                p = p->left;
            } else {
                p = st.top(); st.pop();
                cout << p->val;
                p = p->right;
            }
        }
    }
};


// postorder traverse, recursively
class Solution_post_re {
public:
    void postorder(TreeNode* root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->val << " ";
        }
    }
};

// postorder traverse, stack
class Solution_post_it {
public:
    void postorder(TreeNode* root) {
        if (!root) return;
        TreeNode* pre = NULL; // the last poped node
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode* t = st.top();
                if (t->right && t->right != pre)
                    cur = t->right;
                else {
                    cout << t->val << " ";
                    pre = t;
                    st.pop();
                }
            }
        }
    }
};


// level traverse, queue
class Solution_level {
public:
    void levelorder(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* p = q.front(); q.pop();
            cout << p->val << " ";
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return 0;
}
