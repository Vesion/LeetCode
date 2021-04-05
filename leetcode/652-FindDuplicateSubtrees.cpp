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
    unordered_map<string, int> m;
    vector<TreeNode*> res;

    string serialize(TreeNode* root) {
        if (!root) return "#";
        const string s =
            "(" + serialize(root->left) + to_string(root->val)
            + serialize(root->right) + ")";
        auto it = m.find(s);
        if (it != m.end() && it->second == 1) res.push_back(root);
        ++m[s];
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return res;
    }
};


int main() {
  return 0;
}
