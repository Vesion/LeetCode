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

// Solution 1 : level order traversal, verbose


// Solution 2 : preorder traversal
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;
        int res = root->val, maxrow = 0;
        preorder(root, 0, maxrow, res);
        return res;
    }
    
    void preorder(TreeNode* root, int row, int& maxrow, int& res) {
        if (!root) return;
        if (row > maxrow) { res = root->val; maxrow = row; }
        preorder(root->left, row+1, maxrow, res);
        preorder(root->right, row+1, maxrow, res);
    }
};


int main() {
    return 0;
}
