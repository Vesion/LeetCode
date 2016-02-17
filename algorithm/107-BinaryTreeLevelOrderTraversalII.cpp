#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int len = q.size();
        vector<int> v;
        while (len--) {
            auto it = q.front();
            q.pop();
            if (it->left) q.push(it->left);
            if (it->right) q.push(it->right);
            v.push_back(it->val);
        }
        result.push_back(v);
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(5);
    for (auto i : levelOrderBottom(root)) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
