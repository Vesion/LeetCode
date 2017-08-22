#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
#include <stack> 
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> nums;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (!st.empty() || cur) {
      if (cur) {
        st.push(cur);
        cur = cur->left;
      } else {
        cur = st.top(); st.pop();
        if (nums.count(k-cur->val)) return true;
        nums.insert(cur->val);
        cur = cur->right;
      }
    }
    return false;
  }
};


int main() {
  return 0;
}
