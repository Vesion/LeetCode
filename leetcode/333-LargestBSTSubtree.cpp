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

// postorder
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        int lower, upper;
        postorder(root, res, lower, upper);
        return res;
    }
    
    bool postorder(TreeNode* root, int& res, int& lower, int& upper) {
        if (!root) return true;
        int left_res = 0, right_res = 0;
        int left_lower, left_upper, right_lower, right_upper;
        bool left_is = postorder(root->left, left_res, left_lower, left_upper);
        bool right_is = postorder(root->right, right_res, right_lower, right_upper);
        if (left_is && right_is && (!root->left || root->val > left_upper) && (!root->right || root->val < right_lower)) {
            res = left_res + right_res + 1;
            lower = root->left ? left_lower : root->val;
            upper = root->right ? right_lower : root->val;
            return true;
        }
        res = max(left_res, right_res);
        return false;
    }
};


int main() {
    return 0;
}
