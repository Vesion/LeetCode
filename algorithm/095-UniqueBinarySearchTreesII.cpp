#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
} TreeNode;

TreeNode* insertNode(TreeNode* root, int x) {
    if (!root)
        root = new TreeNode(x);
    else {
        if (x < root->val)
            root->left = insertNode(root->left, x);
        else
            root->right = insertNode(root->right, x);
    }
    return root;
}

void deleteTree(TreeNode* &root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

void printLevelOrder(TreeNode* &root) {
    if (!root)
        cout << "empty tree";
    else {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* it = q.front();
            q.pop();
            cout << it->val << " ";
            if (it->left) q.push(it->left);
            if (it->right) q.push(it->right);
        }
    }
    cout << endl;
}

// generate recursively
vector<TreeNode*> generateSubtrees(int start, int end) {
    vector<TreeNode*> subtrees;
    if (start > end) {
        subtrees.push_back(NULL);
        return subtrees;
    }
    for (int k = start; k <= end; ++k) {
        auto leftsubs = generateSubtrees(start, k-1);
        auto rightsubs = generateSubtrees(k+1, end);
        for (auto i : leftsubs) {
            for (auto j : rightsubs) {
                TreeNode* t = new TreeNode(k);
                t->left = i;
                t->right = j;
                subtrees.push_back(t);
            }
        }
    }
    return subtrees;
}
vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> result;
    if (n == 0) return result;
    return generateSubtrees(1, n);
}

int main() {
    auto trees = generateTrees(3);
    for (auto t : trees)
        printLevelOrder(t);
    return 0;
}
