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
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        isUnival(root, res);
        return res;
    }
    
    bool isUnival(TreeNode* root, int& res) {
        if (!root) return true;
        bool left = isUnival(root->left, res);
        bool right = isUnival(root->right, res);
        if (left && right) {
            if (root->left && root->val != root->left->val) return false;
            if (root->right && root->val != root->right->val) return false;
            ++res;
            return true;
        }
        return false;
    }
};


int main() {
    return 0;
}
