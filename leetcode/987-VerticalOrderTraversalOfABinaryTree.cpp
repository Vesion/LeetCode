#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// bfs
class Solution {
public:
    map<int,vector<int>> m;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        bfs(root);
        vector<vector<int>> res(m.size());
        int i = 0;
        for (auto& p : m) {
            vector<int>& t = p.second;
            res[i++].swap(t);
        }
        return res;
    }

    void bfs(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int len = q.size();
            unordered_map<int, multiset<int>> row;
            while (len--) {
                auto t = q.front(); q.pop();
                TreeNode* cur = t.first;
                int col = t.second;
                row[col].insert(cur->val);
                if (cur->left) q.push({cur->left, col-1});
                if (cur->right) q.push({cur->right, col+1});
            }
            for (const auto& p : row) {
                for (int val : p.second) {
                    m[p.first].push_back(val);
                }
            }
        }
    }
};


// dfs
class Solution1 {
public:
    map<int, map<int, multiset<int>>> m;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> res;
        for (auto& cols : m) {
            res.push_back({});
            for (auto& rows : cols.second) {
                for (int v : rows.second) res.back().push_back(v);
            }
        }
        return res;
    }

    void dfs(TreeNode* root, int row, int col) {
        if (!root) return;
        m[col][row].insert(root->val);
        dfs(root->left, row+1, col-1);
        dfs(root->right, row+1, col+1);
    }
};

int main() {

}
