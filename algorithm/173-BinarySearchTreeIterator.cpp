#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* appendNode(TreeNode* root, int x) {
    if (!root) {
        root = new TreeNode(x);
        return root;
    }
    if (x < root->val) root->left = appendNode(root->left, x);
    else root->right = appendNode(root->right, x);
    return root;
}

void printInorder(TreeNode* root) {
    if (root) {
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
}

void deleteTree(TreeNode* &root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

// similiar to 094-BinaryTreeInorderTraversal solution 2 v2
class BSTIterator {
private:
    stack<TreeNode*> _s;
    inline void pushAll(TreeNode* root) { for (; root; root = root->left) _s.push(root); }
    
public:
    BSTIterator(TreeNode *root) {
        pushAll(root); 
    }

    bool hasNext() {
        return (!_s.empty());
    }

    int next() {
        auto it = _s.top(); _s.pop();
        pushAll(it->right);
        return it->val;
    }
};

int main() {
    TreeNode* root = NULL;
    root = appendNode(root, 4);
    root = appendNode(root, 2);
    root = appendNode(root, 5);
    root = appendNode(root, 1);
    root = appendNode(root, 6);
    root = appendNode(root, 3);
    root = appendNode(root, 0);
    printInorder(root);
    cout << endl;

    BSTIterator it(root);
    while (it.hasNext()) cout << it.next() << " ";
    cout << endl;

    deleteTree(root);
}
