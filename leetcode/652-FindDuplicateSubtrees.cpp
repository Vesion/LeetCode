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
    unordered_map<string, vector<TreeNode*>> trees;

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        vector<TreeNode*> res;
        for (const auto& p : trees) {
            if (p.second.size() > 1) res.push_back(p.second[0]);
        }
        return res;
    }

    string serialize(TreeNode* node) {
        if (node == nullptr) return "#";
        const string s = "(" + serialize(node->left) +
                         to_string(node->val) +
                         serialize(node->right) + ")";
        trees[s].push_back(node);
        return s;
    }
};


int main() {
  return 0;
}
