#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack> 
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// Inorder traversal with stack
class Solution {
public:
  int minDiffInBST(TreeNode* root) {
    int res = INT_MAX;
    stack<TreeNode*> st;
    TreeNode *cur = root, *pre = NULL;
    while (!st.empty() || cur) {
      if (cur) {
        st.push(cur);
        cur = cur->left;
      } else {
        cur = st.top(); st.pop();
        if (pre) res = min(res, cur->val - pre->val);
        pre = cur;
        cur = cur->right;
      }
    }
    return res;
  }
};


int main() {
  return 0;
}
