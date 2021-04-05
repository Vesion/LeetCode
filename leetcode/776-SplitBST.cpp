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

// https://leetcode.com/problems/split-bst/discuss/113798/C%2B%2BEasy-recursion-in-O(n)
class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        // 0 for tree <= V, 1 for tree > V
        vector<TreeNode*> res(2, nullptr);
        if (!root) return res;
        if (root->val > V) {
            res[1] = root;
            auto left_res = splitBST(root->left, V);
            root->left = left_res[1];
            res[0] = left_res[0];
        } else {
            res[0] = root;
            auto right_res = splitBST(root->right, V);
            root->right = right_res[0];
            res[1] = right_res[1];
        }
        return res;
    }
};

int main() {
    return 0;
}
