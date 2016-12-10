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


// bottom up
class Solution {
public:
    int rob(TreeNode* root) {
        auto r = dfs(root);
        return max(r[0], r[1]);
    }

    vector<int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        vector<int> res(2);
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        res[1] = left[0] + right[0] + root->val;
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

