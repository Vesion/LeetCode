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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        inorder(root, sum);
        return root;
    }
    
    void inorder(TreeNode* root, int& sum) {
        if (!root) return;
        inorder(root->right, sum);
        root->val += sum;
        sum = root->val;
        inorder(root->left, sum);
    }
};


int main() {
    return 0;
}
