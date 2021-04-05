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
    unordered_set<int> m;

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i : to_delete) m.insert(i);
        if (dfs(root)) res.push_back(root);
        return res;
    }

    bool dfs(TreeNode* root) {
        if (!root) return false;
        auto it = m.find(root->val);
        bool has_left = dfs(root->left);
        bool has_right = dfs(root->right);
        if (it != m.end()) {
            if (has_left) res.push_back(root->left);
            if (has_right) res.push_back(root->right);
            m.erase(it);
            return false;
        } else {
            if (!has_left) root->left = nullptr;
            if (!has_right) root->right = nullptr;
            return true;
        }
    }
};


int main() {
}
