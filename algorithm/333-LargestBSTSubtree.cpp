#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// Bottom up, O(n)
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        int lower, upper;
        isBST(root, lower, upper, res);
        return res;
    }

    bool isBST(TreeNode* root, int& lower, int& upper, int& res) {
        if (!root) return true;
        int left_num = 0, right_num = 0;
        int left_lower, left_upper, right_lower, right_upper;

        bool left_is = isBST(root->left, left_lower, left_upper, left_num);
        bool right_is = isBST(root->right, right_lower, right_upper, right_num);

        if (left_is && right_is) {
            if ((!root->left || left_upper < root->val) && (!root->right || root->val < right_lower)) {
                res = left_num + right_num + 1;
                lower = root->left ? left_lower : root->val;
                upper = root->right ? right_lower : root->val;
                return true;
            }
        }
        res = max(left_num, right_num);
        return false;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);

    root->right = new TreeNode(15);
    root->right->right = new TreeNode(17);
    cout << s.largestBSTSubtree(root) <<endl;
    return 0;
}
