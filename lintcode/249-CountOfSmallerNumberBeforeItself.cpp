#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int maxn = 1e4+8;

struct SegmentNode {
    int start, end, mid;
    int count = 0;
    SegmentNode *left, *right;
    SegmentNode(int s, int e, int m) : start(s), end(e), mid(m), left(NULL), right(NULL) {}
};

class SegmentTree {
private:
    SegmentNode* root;

    SegmentNode* build(int start, int end) {
        if (start >= end) return NULL;
        if (start+1 == end) {
            return new SegmentNode(start, end, start);
        }
        SegmentNode* root = new SegmentNode(start, end, (start+end)/2);
        root->left = build(start, root->mid);
        root->right = build(root->mid, end);
        return root;
    }

    void modify(SegmentNode* root, int index, int value) {
        if (!root || index < root->start || index >= root->end) return;
        if (index == root->start && index == root->end-1) {
            root->count += value;
            return;
        }
        if (index < root->mid) modify(root->left, index, value);
        else modify(root->right, index, value);
        root->count = root->left->count + root->right->count;
    }

    int query(SegmentNode* root, int start, int end) {
        if (!root || end <= root->start || start >= root->end) return 0;
        if (start <= root->start && end >= root->end) return root->count;
        if (end <= root->mid) return query(root->left, start, end);
        else if (start >= root->mid) return query(root->right, start, end);
        else return query(root->left, start, root->mid) + query(root->right, root->mid, end);
    }

    void print(SegmentNode* root) {
        if (root) {
            print(root->left);
            cout << root->start << " " << root->end << " " << root->count << endl;
            print(root->right);
        }
    }

public:
    SegmentTree() {
        this->root = build(0, maxn);
    }

    void modify(int index, int value) {
        modify(root, index, value);
    }

    int query(int start, int end) {
        return query(root, start, end);
    }
};


class Solution {
public:
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        if (A.empty()) return {};
        int n = A.size();
        vector<int> result(n);
        SegmentTree st;
        for (int i = 0; i < n; ++i) {
            st.modify(A[i], 1);
            result[i] = st.query(0, A[i]);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> A = {32, 34};
    auto r = s.countOfSmallerNumberII(A);
    for (auto i : r) cout << i << " "; cout << endl;
    return 0;
}
