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


// Solution 1 : the inorder traversal generates ordered sequence
class Solution_1 {
public:
    vector<int> nums;

    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);
            nums.push_back(root->val);
            inorder(root->right);
        }
    }

    bool isValidBST(TreeNode *root) {
        inorder(root);
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] <= nums[i-1]) return false;
        }
        return true;
    }  
};


// Solution 2 : MIN MAX
class Solution {
public:
    bool isValid(TreeNode* root, long left, long right) {
        if (!root) return true;
        return ((root->val > left && root->val < right)
                && (isValid(root->left, left, root->val))
                && (isValid(root->right, root->val , right)));
    }

    bool isValidBST(TreeNode *root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};

int main() {
    Solution s;
    return 0;
}
