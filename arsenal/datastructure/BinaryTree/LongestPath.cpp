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


// 编程之美3.8，寻找一棵二叉树中距离最远的两个节点，即最长路径
// 注意该路径是从任一叶子节点出发，到任一叶子节点结束

class Solution {
public:
    int longestPath(TreeNode* root) {
        int res = 0;
        postorder(root, res);
        return res;
    }

    int postorder(TreeNode* root, int& res) {
        if (!root) return 0;
        int left = postorder(root->left, res);
        int right = postorder(root->right, res);
        res = max(res, left + right + 1);
        return max(left, right) + 1;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(1);
    root->left->left->left = new TreeNode(1);
    root->left->right->right = new TreeNode(1);
    root->left->left->left->left = new TreeNode(1);
    root->left->right->right->right = new TreeNode(1);

    Solution s;
    cout << s.longestPath(root) << endl;
    return 0;
}
