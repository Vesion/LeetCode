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

// https://leetcode.com/problems/find-leaves-of-binary-tree/

// Solution 1 : postorder, O(n)
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        postorder(root, res);
        return res;
    }
    
    int postorder(TreeNode* root, vector<vector<int>>& res) {
        if (!root) return -1;
        int left = postorder(root->left, res);
        int right = postorder(root->right, res);
        int level = max(left, right) + 1; // the height count from bottom
        if (level == (int)res.size()) res.push_back({root->val});
        else res[level].push_back(root->val);
        return level;
    }
};


// Solution 2 : convert it into graph, BFS, verbose, O(n)
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
    return 0;
}
