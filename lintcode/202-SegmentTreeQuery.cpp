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
    int query(SegmentTreeNode *root, int start, int end) {
        if (!root || start > end || start > root->end || end < root->start) return 0;
        if (root->start >= start && root->end <= end) return root->max;
        int mid = (root->start+root->end) / 2;
        if (end <= mid) return query(root->left, start, end);
        else if (start >= mid+1) return query(root->right, start, end);
        return max(query(root->left, start, mid), query(root->right, mid+1, end));
    }
};

int main() {
    Solution s;
    return 0;
}


