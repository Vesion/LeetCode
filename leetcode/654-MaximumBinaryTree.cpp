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

// Solution 1 : trivial, preorder
class Solution_1 {
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) { 
    return build(nums, 0, nums.size()-1);
  }

  TreeNode* build(vector<int>& nums, int left, int right) {
    if (left > right) return NULL;
    int mid = left;
    for (int i = left; i <= right; ++i) if (nums[i] > nums[mid]) mid = i;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = build(nums, left, mid-1);
    root->right = build(nums, mid+1, right);
    return root;
  }
};


// Solution 2 : stack, brilliant!
// https://discuss.leetcode.com/topic/98509/c-o-n-solution
class Solution {
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) { 
    vector<TreeNode*> st;
    for (int num : nums) {
      TreeNode* cur = new TreeNode(num);
      while (!st.empty() && num > st.back()->val) {
        cur->left = st.back();
        st.pop_back();
      }
      if (!st.empty()) st.back()->right = cur;
      st.push_back(cur);
    }
    return st.front();
  }
};


int main() {
  return 0;
}
