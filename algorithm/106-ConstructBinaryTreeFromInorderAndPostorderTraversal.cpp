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
