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
            TreeNode* cur = q.front().first;
            int col = q.front().second;
            q.pop();
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
    return 0;
}
