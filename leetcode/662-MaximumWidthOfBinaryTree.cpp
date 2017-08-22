#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
  int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int res = 1;
    while (!q.empty()) {
      int len = q.size();
      int l = q.front().second;
      int r = l;
      while (len--) {
        auto p = q.front(); q.pop();
        TreeNode* t = p.first;
        int c = p.second;
        r = c;
        if (t->left) q.push({t->left, 2*c+1});
        if (t->right) q.push({t->right, 2*c+2});
      }
      res = max(res, r-l+1);
    }
    return res;
  }
};


int main() {
  TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(1);
  root->right->right = new TreeNode(1);
  root->right->right->right = new TreeNode(1);
  root->right->right->right->right = new TreeNode(1);
  Solution s;
  cout << s.widthOfBinaryTree(root) << endl;
  return 0;
}
