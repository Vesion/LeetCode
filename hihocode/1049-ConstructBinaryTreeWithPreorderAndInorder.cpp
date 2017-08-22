#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

string preorder, inorder, postorder;

TreeNode* construct(int ps, int pe, int is, int ie) {
    if (ps >= pe || is >= ie) return NULL;
    char v = preorder[ps];
    int imid = is;
    while (imid < ie && inorder[imid] != v) ++imid;
    TreeNode* root = new TreeNode(v);
    root->left = construct(ps+1, ps+1+imid-is, is, imid);
    root->right = construct(ps+1+imid-is, pe, imid+1, ie);
    return root;
}

void post(TreeNode* root) {
    if (root) {
        post(root->left);
        post(root->right);
        postorder += root->val;
    }
}

int main() {
    cin >> preorder >> inorder;
    TreeNode* root = construct(0, preorder.size(), 0, inorder.size());
    post(root);
    cout << postorder << endl;
    return 0;
}
