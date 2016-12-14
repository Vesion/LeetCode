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


// Solution 1 : bottom up dfs, O(n)
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* root, vector<vector<int>>& res) {
        if (!root) return -1;
        int height = max(dfs(root->left, res), dfs(root->right, res)) + 1;
        if (height >= (int)res.size())
            res.push_back({root->val});
        else
            res[height].push_back(root->val);
        return height;
    }
};


// Solution 2 : convert it into graph, BFS, O(n)
// 脑子抽了，以为跟310-MinimumHeightTrees类似...
class Solution_2 {
public:
    unordered_map<TreeNode*, unordered_set<TreeNode*>> graph;
    unordered_map<TreeNode*, int> indegrees;

    vector<vector<int>> findLeaves(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        make(root);
        vector<TreeNode*> cur, next;
        for (auto& p : indegrees) if (p.second == 0) cur.push_back(p.first);
        while (true) {
            vector<int> leaves;
            for (TreeNode* leaf : cur) {
                indegrees[leaf] = -1;
                leaves.push_back(leaf->val);
                for (TreeNode* nbr : graph[leaf]) {
                    if (--indegrees[nbr] == 0) next.push_back(nbr);
                }
            }
            res.push_back(leaves);
            if (next.empty()) break;
            cur = next;
            next.clear();
        }
        return res;
    }

    void make(TreeNode* root) {
        if (!root) return;
        indegrees[root] = 0;
        if (root->left) {
            graph[root->left].insert(root);
            indegrees[root]++;
        }
        if (root->right) {
            graph[root->right].insert(root);
            indegrees[root]++;
        }
        make(root->left);
        make(root->right);
    }
};

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    auto r = s.findLeaves(root);
    for (auto& i : r) {
        for (auto& j : i) { cout << j << " "; }
        cout << endl;
    }
    return 0;
}
