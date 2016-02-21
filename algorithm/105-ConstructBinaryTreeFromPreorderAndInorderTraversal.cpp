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

TreeNode* build(vector<int>::iterator pre_start, vector<int>::iterator pre_end, 
        vector<int>::iterator in_start, vector<int>::iterator in_end) {
    if (pre_start == pre_end) return NULL;
    if (in_start == in_end) return NULL;
    TreeNode* root = new TreeNode(*pre_start);
    auto in_partition = find(in_start, in_end, *pre_start);
    auto left_size = distance(in_start, in_partition);
    root->left = build(next(pre_start), next(pre_start, left_size+1), in_start, next(in_start, left_size));
    root->right = build(next(pre_start, left_size+1), pre_end, next(in_partition), in_end);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}

int main() {
    vector<int> preorder({1, 2, 4, 3, 5, 6, 7});
    vector<int> inorder({4, 2, 1, 3, 6, 5, 7});
    //vector<int> preorder({1, 2, 3, 4});
    //vector<int> inorder({2, 1, 3, 4});
    auto root = buildTree(preorder, inorder);
    printPreorder(root);
    cout << endl;
    printInorder(root);
    cout << endl;
    deleteTree(root);
    return 0;
}
