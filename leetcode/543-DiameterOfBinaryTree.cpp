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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        postorder(root, res);
        return res;
    }
    
    int postorder(TreeNode* root, int& res) {
        if (!root) return 0;
        int left = postorder(root->left, res);
        int right = postorder(root->right, res);
        res = max(res, left+right);
        return max(left, right) + 1;
    }
};


int main() {
    return 0;
}
