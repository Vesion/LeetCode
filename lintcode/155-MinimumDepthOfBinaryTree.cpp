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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            auto n = t.first;
            if (!n->left && !n->right) return t.second;
            if (n->left) q.push({n->left, t.second+1});
            if (n->right) q.push({n->right, t.second+1});
        }
        return 0;
    }
};

int main() {
    Solution s;
    return 0;
}
