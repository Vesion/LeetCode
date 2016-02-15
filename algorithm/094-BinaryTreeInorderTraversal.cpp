#include <iostream>
#include <vector>
#include <stack>
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
    root = NULL; // do not forget set root to NULL, in case of invalid usage
}

// Solution 1 : recursive, trivial
void inorder(TreeNode* &root, vector<int>& result) {
    if (root) {
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
}
vector<int> inorderTraversal_re(TreeNode* root) {
    vector<int> result;
    inorder(root, result);
    return result;
}

// Solution 2 : iterative, use stack
vector<int> inorderTraversal_it(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* it = root;
    while (it || !s.empty()) {
        if (it) {
            s.push(it);
            it = it->left;
        } else {
            it = s.top();
            s.pop();
            result.push_back(it->val);
            it = it->right;
        }
    }
    return result;
}

int main() {
    TreeNode* root = NULL;
    root = insertNode(root, 1);
    root = insertNode(root, 8);
    root = insertNode(root, 9);
    for (auto i : inorderTraversal_it(root))
        cout << i << " ";
    cout << endl;

    deleteTree(root);
    return 0;
}
