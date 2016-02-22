#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

void dfs(vector<vector<int>>& result, vector<int>& path, TreeNode* root, int sum) {
    if (!root) return;

    path.push_back(root->val); 

    if (!root->left && !root->right) {
        if (root->val == sum)
            result.push_back(path);
    }

    dfs(result, path, root->left, sum-root->val);
    dfs(result, path, root->right, sum-root->val);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(result, path, root, sum);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    auto r = pathSum(root, 6);
    for (auto i : r) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    deleteTree(root);
    return 0;
}
