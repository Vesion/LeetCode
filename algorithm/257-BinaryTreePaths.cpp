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
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}

void dfs(vector<string>& result, string path, TreeNode* root) {
    if (!root->left && !root->right) {
        result.push_back(path);
        return;
    }
    if (root->left) dfs(result, path + "->" + to_string(root->left->val), root->left);
    if (root->right) dfs(result, path + "->" + to_string(root->right->val), root->right);
}

vector<string> binaryTreePaths(TreeNode* root) {
    if (!root) return {};
    vector<string> result;
    dfs(result, to_string(root->val), root);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);

    auto r = binaryTreePaths(root);
    for (auto i : r) cout << i << ' '; cout << endl;

    deleteTree(root);
    return 0;
}
