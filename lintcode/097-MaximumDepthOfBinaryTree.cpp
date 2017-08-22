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
    int result = 0;
    void dfs(TreeNode* root, int depth) {
        if (!root) {
            result = max(result, depth);
            return;
        }
        depth++;
        dfs(root->left, depth);
        dfs(root->right, depth);
    }
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        dfs(root, 0);
        return result;
    }    
};

int main() {
    Solution s;
    return 0;
}
