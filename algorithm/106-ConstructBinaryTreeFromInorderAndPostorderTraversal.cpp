#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void deleteTree(TreeNode* &root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

void printPreorder(TreeNode* root) {
    if (root) {
        cout << root->val << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printInorder(TreeNode* root) {
    if (root) {
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }
}

void printPostorder(TreeNode* root) {
    if (root) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->val << " ";
    }
}

TreeNode* build(vector<int>::iterator post_start, vector<int>::iterator post_end, 
        vector<int>::iterator in_start, vector<int>::iterator in_end) {
    if (post_start == post_end) return NULL;
    if (in_start == in_end) return NULL;

    const int val = *prev(post_end);
    TreeNode* root = new TreeNode(val);
    auto in_partition = find(in_start, in_end, val);
    auto left_size = distance(in_start, in_partition);

    root->left = build(post_start, next(post_start, left_size), in_start, in_partition);
    root->right = build(next(post_start, left_size), prev(post_end), next(in_partition), in_end);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return build(postorder.begin(), postorder.end(), inorder.begin(), inorder.end());
}

int main() {
    vector<int> preorder({1, 2, 4, 3, 5, 6, 7});
    vector<int> inorder({4, 2, 1, 3, 6, 5, 7});
    vector<int> postorder({4, 2, 6, 7, 5, 3, 1});
    auto root = buildTree(inorder, postorder);
    printInorder(root);
    cout << endl;
    printPostorder(root);
    cout << endl;
    deleteTree(root);
    return 0;
}

