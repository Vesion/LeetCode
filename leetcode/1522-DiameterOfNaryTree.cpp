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

// similar to 543-DiameterOfBinaryTree
class Solution {
public:
    int res = 0;
    int diameter(Node* root) {
        dfs(root);
        return res;
    }

    int dfs(Node* root) {
        if (!root) return 0;
        int maxl = 0, secondl = 0;
        for (Node* child : root->children) {
            int l = dfs(child);
            if (l > maxl) {
                secondl = maxl;
                maxl = l;
            } else if (l > secondl) {
                secondl = l;
            }
        }
        res = max(res, maxl+secondl);
        return maxl+1;
    }
};

int main() {

}