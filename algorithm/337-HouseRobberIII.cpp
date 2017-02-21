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

// recursive postorder
class Solution {
public:
    int rob(TreeNode* root) {
        auto res = postorder(root);
        return max(res[0], res[1]);
    }
    
    vector<int> postorder(TreeNode* root) {
        if (!root) return {0, 0};
        auto left = postorder(root->left);
        auto right = postorder(root->right);
        int notrob = max(left[0], left[1]) + max(right[0], right[1]);
        int rob = root->val + left[0] + right[0];
        return {rob, notrob};
    }
};


int main() {
    return 0;
}
