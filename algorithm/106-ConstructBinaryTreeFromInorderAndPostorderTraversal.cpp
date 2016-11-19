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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }

    TreeNode* build(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe) {
        if (is == ie || ps == pe) return NULL;
        TreeNode* root = new TreeNode(postorder[pe-1]);
        int ir = is;
        while (ir != ie && inorder[ir] != postorder[pe-1]) ir++;
        int len = ir - is;
        root->left = build(inorder, is, ir, postorder, ps, ps+len);
        root->right = build(inorder, ir+1, ie, postorder, ps+len, pe-1);
        return root;
    }
};

int main() {
    Solution s;
    return 0;
}

