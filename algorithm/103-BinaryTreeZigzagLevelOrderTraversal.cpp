#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque> 
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
        deque<TreeNode*> q;
        q.push_back(root);
        bool left = true; // order of current level
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            while (n--) {
                TreeNode* t;
                if (left) {
                    t = q.front(); q.pop_front();
                    if (t->left) q.push_back(t->left);
                    if (t->right) q.push_back(t->right);
                } else {
                    t = q.back(); q.pop_back();
                    if (t->right) q.push_front(t->right);
                    if (t->left) q.push_front(t->left);
                }
                level.push_back(t->val);
            }
            left = !left;
            res.push_back(level);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

