#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        bool left = true;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            vector<int> level(len);
            int i = left ? 0 : len-1;
            while (len--) {
                TreeNode* t = q.front(); q.pop();
                if (left) level[i++] = t->val;
                else level[i--] = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            left = !left;
            res.push_back(level);
        }
        return res;
    }
};


int main() {
    return 0;
}
