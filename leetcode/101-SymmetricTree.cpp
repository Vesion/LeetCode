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
    bool isSymmetric(TreeNode* root) {
        return !root || symmetric(root->left, root->right);
    }

    bool symmetric(TreeNode* p, TreeNode* q) {
        return (!p && !q) || (p && q && p->val == q->val && symmetric(p->left, q->right) && symmetric(p->right, q->left));
    }
};


int main() {
    return 0;
}
