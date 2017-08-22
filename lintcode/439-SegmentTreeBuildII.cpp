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
private:
    SegmentTreeNode* b(vector<int>&A, int left, int right) {
        if (left == right) return new SegmentTreeNode(left, right, A[left]);
        SegmentTreeNode* root = new SegmentTreeNode(left, right, *max_element(A.begin()+left, A.begin()+right+1));
        root->left = b(A, left, (left+right)/2);
        root->right = b(A, (left+right)/2+1, right);
        return root;
    }

public:
    SegmentTreeNode * build(vector<int>& A) {
        if (A.empty()) return NULL;
        return b(A, 0, A.size()-1);
    }
};

int main() {
    Solution s;
    return 0;
}

