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


// Solution: convert binary tree into an undirected graph, then bfs to find the shortest path
class Solution {
public:
  static const int MAXN = 1e3+5;
  vector<int> g[MAXN];
  bool visit[MAXN], leaf[MAXN];

  int findClosestLeaf(TreeNode* root, int k) {
    memset(visit, 0, sizeof visit);
    memset(leaf, 0, sizeof leaf);
    build(root);
    queue<int> q;
    q.push(k); visit[k] = true;
    while (!q.empty()) {
      int t = q.front(); q.pop();
      if (leaf[t]) return t;
      for (int nbr : g[t]) {
        if (!visit[nbr]) {
          q.push(nbr); visit[nbr] = true;
        }
      }
    }
    return 0; // never
  }

  void build(TreeNode* root) {
    if (!root) return;
    if (root->left) { g[root->val].push_back(root->left->val); g[root->left->val].push_back(root->val); }
    if (root->right) { g[root->val].push_back(root->right->val); g[root->right->val].push_back(root->val); }
    if (!root->left && !root->right) leaf[root->val] = true;
    build(root->left);
    build(root->right);
  }
};


int main() {
  TreeNode* root = new TreeNode(1);
  Solution s;
  cout << s.findClosestLeaf(root, 1) << endl;
  return 0;
}
