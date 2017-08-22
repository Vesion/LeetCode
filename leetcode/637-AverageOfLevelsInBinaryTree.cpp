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
  vector<double> averageOfLevels(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    vector<double> res;
    while (!q.empty()) {
      int n = q.size(), c = q.size();
      long long sum = 0;
      while (c--) {
        TreeNode* t = q.front(); q.pop();
        sum += t->val;
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
      res.push_back(1.0 * sum / n);
    }
    return res;
  }
};


int main() {
  return 0;
}
