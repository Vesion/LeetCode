#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class SegmentTreeNode {
public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) {
        this->start = start;
        this->end = end;
        this->max = max;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    void modify(SegmentTreeNode *root, int index, int value) {
        if (!root || index < root->start || index > root->end) return;
        if (root->start == index && root->end == index) {
            root->max = value;
            return;
        }
        int mid = (root->start + root->end) / 2;
        if (index <= mid) modify(root->left, index, value);
        else modify(root->right, index, value);
        root->max = max(root->left->max, root->right->max);
    }
};

int main() {
    Solution s;
    return 0;
}
