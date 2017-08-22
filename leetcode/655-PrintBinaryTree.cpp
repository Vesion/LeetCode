#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<string>> printTree(TreeNode* root) { 
    vector<int> cols;
    getCols(root, 0, cols);
    vector<vector<string>> res(cols.size(), vector<string>(cols[0], ""));
    print(root, cols.size()-1, cols[0]/2, res);
    reverse(res.begin(), res.end());
    return res;
  }

  int getCols(TreeNode* root, int row, vector<int>& cols) {
    if (!root) return 0;
    if ((int)cols.size() == row) cols.push_back(0);
    int left = getCols(root->left, row+1, cols);
    int right = getCols(root->right, row+1, cols);
    cols[row] = max(cols[row], 2*max(left, right)+1);
    return cols[row];
  }

  void print(TreeNode* root, int row, int col, vector<vector<string>>& res) {
    if (!root) return;
    res[row][col] = to_string(root->val);
    print(root->left, row-1, col-(1<<(row-1)), res);
    print(root->right, row-1, col+(1<<(row-1)), res);
  }
};


int main() {
  Solution s;
  TreeNode* root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);
  auto r = s.printTree(root);
  for (auto& i : r) {
    for (auto& j : i) { cout << j << " "; }
    cout << endl;
  }
  return 0;
}
