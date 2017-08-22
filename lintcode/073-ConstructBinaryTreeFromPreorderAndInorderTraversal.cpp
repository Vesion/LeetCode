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
    vector<int> preorder, inorder;

    TreeNode* build(int pre_start, int pre_end, int in_start, int in_end) {
        if (pre_start == pre_end) return NULL;
        if (in_start == in_end) return NULL;

        TreeNode* root = new TreeNode(preorder[pre_start]);
        int in_root = 0;
        for (int i = in_start; i < in_end; ++i) {
            if (inorder[i] == preorder[pre_start]) {
                in_root = i;
                break;
            }
        }
        int in_dist = in_root-in_start;

        root->left = build(pre_start+1, pre_start+in_dist+1, in_start, in_root);
        root->right = build(pre_start+in_dist+1, pre_end, in_root+1, in_end);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        return build(0, preorder.size(), 0, inorder.size());
    }    
};

int main() {
    Solution s;
    return 0;
}
