#include <iostream>
#include <vector>
#include <queue>
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

// Solution 1 : level order traversal
vector<int> rightSideView_level(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int len = q.size();
        int val;
        while (len--) {
            auto node = q.front(); q.pop();
            val = node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(val);
    }
    return result;
}


// Solution 2 : preorder traversal, root-right-left
void dfs(TreeNode* root, int level, vector<int>& result) {
    if (!root) return;
    if (level > result.size()) result.push_back(root->val);
    dfs(root->right, level+1, result);
    dfs(root->left, level+1, result);
}

vector<int> rightSideView_pre(TreeNode* root) {
    vector<int> result;
    dfs(root, 1, result);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(7);
    auto result = rightSideView_level(root);
    for (auto i:result) cout << i << " "; cout << endl;
    result = rightSideView_pre(root);
    for (auto i:result) cout << i << " "; cout << endl;

    deleteTree(root);
    return 0;
}
