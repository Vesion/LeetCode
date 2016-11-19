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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if (ps == pe || is == ie) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int ir = is;
        while (ir != ie && inorder[ir] != preorder[ps]) ++ir;
        int len = ir - is;
        root->left = build(preorder, ps+1, ps+len+1, inorder, is, ir);
        root->right = build(preorder, ps+len+1, pe, inorder, ir+1, ie);
        return root;
    }
};

int main() {
    Solution s;
    return 0;
}

