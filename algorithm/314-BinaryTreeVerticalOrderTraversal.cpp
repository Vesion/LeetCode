#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
#include <unordered_set> 
#include <queue> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            TreeNode* cur = t.first;
            int col = t.second;
            m[col].push_back(cur->val);
            if (cur->left) q.push({cur->left, col-1});
            if (cur->right) q.push({cur->right, col+1});
        }
        vector<vector<int>> res;
        for (auto& p : m) res.push_back(p.second);
        return res;
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->left->left= new TreeNode(8);
    root->right->right = new TreeNode(9);
    root->left->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    auto r = s.verticalOrder(root);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}
