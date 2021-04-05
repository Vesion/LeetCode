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

// Solution 0: Convert the tree to a graph, then do bfs.


// Solution 1 : Firstly find the path from root to target,
// store distance between each node on the path and target. Then traverse the tree.
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/discuss/143798/1ms-beat-100-simple-Java-dfs-with(without)-hashmap-including-explanation
class Solution {
public:
    unordered_map<TreeNode*,int> dist;
    vector<int> res;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return res;
        find(root, target);
        dfs(root, dist[root], k);
        return res;
    }

    int find(TreeNode* root, TreeNode* target) {
        if (!root) return -1;
        if (root == target) {
            dist[root] = 0;
            return 0;
        }
        int left = find(root->left, target);
        if (left >= 0) {
            dist[root] = left+1;
            return left+1;
        }
        int right = find(root->right, target);
        if (right >= 0) {
            dist[root] = right+1;
            return right+1;
        }
        return -1;
    }

    void dfs(TreeNode* root, int len, int k) {
        if (!root) return;
        if (dist.count(root)) len = dist[root];  // if this node is in the path root->target, just use the dist
        if (len == k) res.push_back(root->val);
        dfs(root->left, len+1, k);
        dfs(root->right, len+1, k);
    }
};


int main() {
}
