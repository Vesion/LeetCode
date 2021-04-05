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


// Construct a binary tree with preorder+inorder / inorder+postorder


// preorder + inorder
class Solution_pre_in {
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


// inorder + postorder
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    
    TreeNode* build(vector<int>& inorder, int istart, int iend, vector<int>& postorder, int pstart, int pend) {
        if (istart >= iend || pstart >= pend) return NULL;
        int val = postorder[pend-1];
        int imid = istart;
        while (imid < iend && inorder[imid] != val) ++imid;
        TreeNode* root = new TreeNode(val);
        root->left = build(inorder, istart, imid, postorder, pstart, pstart+imid-istart);
        root->right = build(inorder, imid+1, iend, postorder, pstart+imid-istart, pend-1);
        return root;
    }
};


int main() {
    return 0;
}
