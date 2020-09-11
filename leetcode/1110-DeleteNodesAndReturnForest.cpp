#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// Postorder
class Solution {
public:
    vector<TreeNode*> res;
    unordered_set<int> ds;

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root) return res;
        for (int d : to_delete) ds.insert(d);
        if (!dfs(root)) res.push_back(root);
        return res;
    }

    bool dfs(TreeNode* node) {
        if (!node) return true;
        bool f = ds.count(node->val);
        bool fl = dfs(node->left), fr = dfs(node->right);
        if (f) {
            if (!fl) res.push_back(node->left);
            if (!fr) res.push_back(node->right);
        } else {
            if (fl) node->left = nullptr;
            if (fr) node->right = nullptr;
        }
        return f;
    }
};


int main() {
}
