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
    
    TreeNode* build(vector<int>& preorder, int pstart, int pend, vector<int>& inorder, int istart, int iend) {
        if (pstart >= pend || istart >= iend) return NULL;
        int imid = istart;
        while (imid < iend && inorder[imid] != preorder[pstart]) ++imid;
        TreeNode* root = new TreeNode(preorder[pstart]);
        root->left = build(preorder, pstart+1, pstart+1+imid-istart, inorder, istart, imid);
        root->right = build(preorder, pstart+1+imid-istart, pend, inorder, imid+1, iend);
        return root;
    }
};


int main() {
    return 0;
}
