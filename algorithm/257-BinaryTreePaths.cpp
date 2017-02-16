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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> res;
        preorder(root, to_string(root->val), res);
        return res;
    }
    
    void preorder(TreeNode* root, string path, vector<string>& res) {
        if (!root->left && !root->right) {
            res.push_back(path);
            return;
        }
        if (root->left) preorder(root->left, path+"->"+to_string(root->left->val), res);
        if (root->right) preorder(root->right, path+"->"+to_string(root->right->val), res);
    }
};


int main() {
    return 0;
}
