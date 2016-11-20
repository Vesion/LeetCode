#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode* cur = root; // current node in current level

            TreeLinkNode* prev = NULL; // record the pre node in next level
            TreeLinkNode* first = NULL; // find the first node in next level
            while (cur) {
                if (!first) first = cur->left ? cur->left : cur->right;
                if (cur->left) {
                    if (prev) prev->next = cur->left;
                    prev = cur->left;
                }
                if (cur->right) {
                    if (prev) prev->next = cur->right;
                    prev = cur->right;
                }
                cur = cur->next;
            }
            root = first;
        }
    }
};

int main() {
    Solution s;
    return 0;
}

