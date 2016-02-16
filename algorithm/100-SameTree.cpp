#include <iostream>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

TreeNode* insertNode(TreeNode* root, int x) {
    if (!root)
        root = new TreeNode(x);
    else {
        if (x < root->val)
            root->left = insertNode(root->left, x);
        else
            root->right = insertNode(root->right, x);
    }
    return root;
}

void deleteTree(TreeNode* &root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    return (!p && !q) || (p && q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int main() {
    TreeNode *t1 = NULL, *t2 = NULL;

    t1 = insertNode(t1, 5);
    t1 = insertNode(t1, 3);
    t1 = insertNode(t1, 7);
    t1 = insertNode(t1, 2);
    t1 = insertNode(t1, 8);

    t2 = insertNode(t2, 5);
    t2 = insertNode(t2, 3);
    t2 = insertNode(t2, 7);
    t2 = insertNode(t2, 2);
    t2 = insertNode(t2, 8);

    cout << isSameTree(t1, t2);

    deleteTree(t1);
    deleteTree(t2);
    return 0;
}
