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
    root = NULL;
}

// Solution 1 : recursively, trivial
void preorder(TreeNode* root, vector<int>& result) {
    if (root) {
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
}
vector<int> preorderTraversal_re(TreeNode* root) {
    vector<int> result;
    preorder(root, result);
    return result;
}

// Solution 2 : iteratively
vector<int> preorderTraversal_it(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* it = root;
    while (it || !s.empty()) {
        if (it) {
            result.push_back(it->val);
            s.push(it);
            it = it->left;
        } else {
            it = s.top();
            s.pop();
            it = it->right;
        }
    }
    return result;
}

int main() {
    TreeNode* root = NULL;
    root = insertNode(root, 4);
    root = insertNode(root, 8);
    root = insertNode(root, 9);
    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    for (auto i : preorderTraversal_it(root))
        cout << i << " ";
    cout << endl;
    return 0;
}
