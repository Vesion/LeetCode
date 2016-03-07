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

// similiar to 094-BinaryTreeInorderTraversal stack solution
class BSTIterator {
private:
    stack<TreeNode*> _s;
    TreeNode* _it;
public:
    BSTIterator(TreeNode *root) {
        _it = root;
    }

    bool hasNext() {
        return (_it || !_s.empty());
    }

    int next() {
        while (true) {
            if (_it) { _s.push(_it); _it = _it->left; }
            else {
                _it = _s.top(); _s.pop();
                auto t = _it;
                _it = _it->right;
                return t->val;
            }
        }
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
