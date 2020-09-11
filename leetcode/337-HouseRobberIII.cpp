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
    unordered_map<TreeNode*, int[2]> dp;

    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        rob(root->left);
        rob(root->right);
        auto& left = dp[root->left];
        auto& right = dp[root->right];
        auto& cur = dp[root];
        cur[0] = max(left[0], left[1]) + max(right[0], right[1]);
        cur[1] = root->val + left[0] + right[0];
        return max(cur[0], cur[1]);
    }
};


int main() {
    return 0;
}
