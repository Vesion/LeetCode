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
  int longestUnivaluePath(TreeNode* root) {
    if (!root) return 0;
    int res = 0;
    postorder(root, res);
    return res;
  }

  int postorder(TreeNode* root, int& res) {
    if (!root) return 0;
    int left = postorder(root->left, res);
    int right = postorder(root->right, res);
    int l = (root->left && root->left->val == root->val) ? left+1 : 0;
    int r = (root->right && root->right->val == root->val) ? right+1 : 0;
    res = max(res, l+r);
    return max(l, r);
  }
};


int main() {
  return 0;
}
