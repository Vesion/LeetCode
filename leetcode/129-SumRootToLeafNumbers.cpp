#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    int res = 0;
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* root, int path) {
        if (!root) return;
        path = path*10 + root->val;
        if (!root->left && !root->right) res += path;
        if (root->left) dfs(root->left, path);
        if (root->right) dfs(root->right, path);
    }
};


int main() {
    return 0;
}
