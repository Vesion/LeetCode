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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        dfs(root, 0, res);
        return res;
    }
    
    void dfs(TreeNode* root, int num, int& res) {
        if (!root) return;
        num = num*10 + root->val;
        if (!root->left && !root->right) res += num;
        if (root->left) dfs(root->left, num, res);
        if (root->right) dfs(root->right, num, res);
    }
};


int main() {
    return 0;
}
