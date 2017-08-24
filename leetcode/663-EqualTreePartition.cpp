#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool checkEqualTree(TreeNode* root) {
    if (!root || (!root->left && !root->right)) return false;
    unordered_set<int> s;
    int t = sum(root, s);
    return (t%2 == 0) && s.count(t/2);
  }  

  int sum(TreeNode* root, unordered_set<int>& s) {
    if (!root) return 0;
    int t = root->val + sum(root->left, s) + sum(root->right, s);
    s.insert(t);
    return t;
  }
};


int main() {
  return 0;
}
