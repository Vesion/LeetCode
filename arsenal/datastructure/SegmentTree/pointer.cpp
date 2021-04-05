#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Before we have implemented SegmentTree using array, 
// here we use more general form, pointer.


struct SegmentNode {
    int start, end, mid; // [start, end), mid for cache
    long long sum; // extra data, e.g. sum, count, maxNum, minNum ...
    SegmentNode *left, *right;
    SegmentNode(int s, int e, int m) : start(s), end(e), mid(m), left(NULL), right(NULL) {}
};

class SegmentTree {
private:
    SegmentNode* root;
    vector<int> A;

    SegmentNode* build(int start, int end) {
        if (start >= end) return NULL;
        if (start+1 == end) {
            SegmentNode* leaf = new SegmentNode(start, end, start);
            leaf->sum = (long long)A[start]; // extra data init
            return leaf;
        }
        SegmentNode* root = new SegmentNode(start, end, (start+end)/2);
        root->left = build(start, root->mid);
        root->right = build(root->mid, end);
        root->sum = root->left->sum + root->right->sum; // extra data recursive init
        return root;
    }

    // query an interval
    long long query(SegmentNode* root, int start, int end) {
        if (!root || end <= root->start || start >= root->end) return 0l;
        if (start <= root->start && end >= root->end) return root->sum;
        if (end <= root->mid) return query(root->left, start, end);
        else if (start >= root->mid) return query(root->right, start, end);
        else return query(root->left, start, root->mid) + query(root->right, root->mid, end);
    }

    // modify one point
    void modify(SegmentNode* root, int index, int value) {
        if (!root || index < root->start || index >= root->end) return;
        if (index == root->start && index == root->end-1) {
            root->sum = value;
            return;
        }
        if (index < root->mid) modify(root->left, index, value);
        else modify(root->right, index, value);
        root->sum = root->left->sum + root->right->sum;
    }

    // print tree in preordr
    void print(SegmentNode* root) {
        if (root) {
            print(root->left);
            cout << root->start << " " << root->end << " " << root->sum << endl;
            print(root->right);
        }
    }

public:
    SegmentTree(vector<int> A) {
        this->A = A;
        this->root = build(0, A.size());
    }

    long long query(int start, int end) {
        return query(root, start, end);
    }

    void modify(int index, int value) {
        modify(root, index, value);
    }
};


// test case

class Solution {
public:
    SegmentTree* st;
    Solution(vector<int> A) {
        st = new SegmentTree(A);
    }
    
    long long query(int start, int end) {
        return st->query(start, end+1);
    }
    
    void modify(int index, int value) {
        st->modify(index, value);
    }
};

int main() {
    vector<int> A = {1, 2, 7, 8, 5};
    Solution s(A);
    cout << s.query(0, 2) <<endl;;
    s.modify(0, 4);
    cout << s.query(0, 1) << endl;
    s.modify(2, 1);
    cout << s.query(2, 4) << endl;;
    return 0;
}

