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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int res = -1;
        preorder(root, root->val, res);
        return res;
    }

    void preorder(TreeNode* root, int minv, int& res) {
        if (!root) return;
        if (root->val > minv) res = res == -1 ? root->val : min(res, root->val);
        preorder(root->left, minv, res);
        preorder(root->right, minv, res);
    }
};


int main() {
}
