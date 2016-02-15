#include <iostream>
#include <vector>
#include <stack>
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

// Solution 1 : recursively, trivial
void postorder(TreeNode* root, vector<int> &result) {
    if (root) {
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }
}
vector<int> postorderTraversal_re(TreeNode* root) {
    vector<int> result;
    postorder(root, result);
    return result;
}

// Solution 2 : iteratively
vector<int> postorderTraversal_it(TreeNode* root) {
    vector<int> result;
    stack<pair<TreeNode*, bool>> s; // store not only iterator, but a flag representing where has been visited
    TreeNode* it = root;
    while (it || !s.empty()) {
        if (it) {
            s.push(make_pair(it, false));
            it = it->left;
        } else {
            auto &p = s.top();
            if (p.second) { // if its right child has been visited, pop it
                s.pop();
                result.push_back(p.first->val);
            } else { // else, visit its right child first
                p.second = true;
                it = p.first->right;
            }
        }
    }
    return result;
}

// solution 2 another version
vector<int> postorderTraversal_it2(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* cur = root, *prev;
    do {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        prev = NULL;
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            if (cur->right == prev) {
                result.push_back(cur->val);
                prev = cur;
            } else {
                s.push(cur);
                cur = cur->right;
                break;
            }
        }
    } while (!s.empty());
    return result;
}

int main() {
    TreeNode* root = NULL;
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 8);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 9);
    for (auto i : postorderTraversal_it(root))
        cout << i << " ";
    cout << endl;
    return 0;
}
