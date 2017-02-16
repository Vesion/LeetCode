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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while (!q.empty()) {
            int len = q.size();
            int max_value = INT_MIN;
            while (len--) {
                TreeNode* t = q.front(); q.pop();
                max_value = max(max_value, t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(max_value);
        }
        return res;
    }
};


int main() {
    return 0;
}
