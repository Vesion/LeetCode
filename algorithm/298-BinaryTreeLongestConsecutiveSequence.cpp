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
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        dfs(root, 0, res, 0);
        return res;
    }
    
    void dfs(TreeNode* root, int pre, int& res, int len) {
        if (!root) return;
        if (root->val == pre+1) len++;
        else len = 1;
        res = max(res, len);
        dfs(root->left, root->val, res, len);
        dfs(root->right, root->val, res, len);
    } 
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    cout << s.longestConsecutive(root) << endl;
    return 0;
}
