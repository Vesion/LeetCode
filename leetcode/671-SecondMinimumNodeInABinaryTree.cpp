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
  int findSecondMinimumValue(TreeNode* root) {
    if (!root) return -1;
    int res = INT_MAX;
    preorder(root, root->val, res);
    return res == INT_MAX ? -1 : res;
  }

  void preorder(TreeNode* root, int minv, int& res) {
    if (!root) return;
    if (root->val > minv) res = min(res, root->val);
    preorder(root->left, minv, res);
    preorder(root->right, minv, res);
  }
};


int main() {
  return 0;
}
