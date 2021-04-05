#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// Solution 1 : level order traversal, O(logn) space
class Solution_1 {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            TreeLinkNode* pre = NULL;
            while (len--) {
                TreeLinkNode* t = q.front(); q.pop();
                if (pre) pre->next = t;
                pre = t;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
    }
};


// Solution 2 : O(1) space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {  // level by level
            TreeLinkNode *pre = NULL, *cur = root;
            TreeLinkNode* first = NULL;
            while (cur) { // connect the child level
                if (!first) first = cur->left ? cur->left : cur->right;
                if (cur->left) {
                    if (pre) pre->next = cur->left;
                    pre = cur->left;
                }
                if (cur->right) {
                    if (pre) pre->next = cur->right;
                    pre = cur->right;
                }
                cur = cur->next;
            }
            root = first;
        }
    }
};


int main() {
    return 0;
}
