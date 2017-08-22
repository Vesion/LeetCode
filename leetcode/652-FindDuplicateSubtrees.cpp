#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};


// Serialize every subtree into a string, and hash it.
// refer to 297. and 536.
class Solution {
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) { 
    unordered_map<string, vector<TreeNode*>> m;
    serialize(root, m);
    vector<TreeNode*> res;
    for (auto& p : m) if (p.second.size() > 1) res.push_back(p.second[0]);
    return res;
  }

  string serialize(TreeNode* root, unordered_map<string, vector<TreeNode*>>& m) {
    if (!root) return "#";
    string r = "(" + serialize(root->left, m) + to_string(root->val) + serialize(root->right, m) + ")";
    m[r].push_back(root);
    return r;
  }
};


int main() {
  return 0;
}
