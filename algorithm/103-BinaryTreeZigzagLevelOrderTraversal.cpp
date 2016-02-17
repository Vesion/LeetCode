#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    bool left_to_right = true;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int len = q.size();
        vector<int> r;
        while (len--) {
            auto it = q.front();
            q.pop();
            r.push_back(it->val);
            if (it->left) q.push(it->left);
            if (it->right) q.push(it->right);
        }
        if (!left_to_right) reverse(r.begin(), r.end());
        result.push_back(r);
        left_to_right = !left_to_right;
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(0);
    for (auto i : zigzagLevelOrder(root)) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
