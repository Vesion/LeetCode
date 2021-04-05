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
    int res = 0;

    int largestBSTSubtree(TreeNode* root) {
        post(root);
        return res;
    }

    tuple<bool,int,int,int> post(TreeNode* root) {
        if (!root) return {true, 0, 0, 0};
        auto [l_is, l_lower, l_upper, l_count] = post(root->left);
        auto [r_is, r_lower, r_upper, r_count] = post(root->right);
        if (l_is && r_is &&
            (!root->left || l_upper < root->val) &&
            (!root->right || root->val < r_lower)) {
            res = max(res, l_count+r_count+1);
            return {true,
                    root->left ? l_lower : root->val,
                    root->right ? r_upper : root->val,
                    l_count+r_count+1};
        } else {
            return {false, 0, 0, 0};
        }
    }
};

int main() {
    return 0;
}
