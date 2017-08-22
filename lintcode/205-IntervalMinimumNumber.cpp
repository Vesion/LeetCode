#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Interval {
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

struct SegmentNode { // [start, end)
    int start, end, mid;
    int minNum;
    SegmentNode *left, *right;
    SegmentNode(int s, int e, int m) : start(s), end(e), mid(m), left(NULL), right(NULL) {}
};

class SegmentTree {
private:
    SegmentNode* root;

    SegmentNode* build(vector<int>& A, int start, int end) {
        if (start == end) return NULL;
        if (start+1 == end) {
            SegmentNode* leaf = new SegmentNode(start, end, start);
            leaf->minNum = A[start];
            return leaf;
        }
        SegmentNode* root = new SegmentNode(start, end, (start+end)/2);
        root->left = build(A, start, root->mid);
        root->right = build(A, root->mid, end);
        root->minNum = min(root->left->minNum, root->right->minNum);
        return root;
    }

    int query(SegmentNode* root, Interval i) {
        if (!root || i.start >= root->end || i.end <= root->start) return -1; // illegal
        if (i.start == root->start && i.end == root->end) return root->minNum;
        if (i.end <= root->mid) return query(root->left, i);
        else if (i.start >= root->mid) return query(root->right, i);
        else return min(query(root->left, Interval(i.start, root->mid)), query(root->right, Interval(root->mid, i.end)));
    }

    void print(SegmentNode* root) {
        if (root) {
            print(root->left);
            cout << root->start << " " << root->end << " " << root->minNum << endl;
            print(root->right);
        }
    }

public:
    SegmentTree(vector<int>& A) {
        root = build(A, 0, A.size());
    }

    int query(Interval i) {
        return query(root, i);
    }
};



class Solution { 
public:
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        if (A.empty() || queries.empty()) return {};
        vector<int> result;
        SegmentTree st(A);
        for (auto &i : queries) result.push_back(st.query(Interval(i.start, i.end+1)));
        return result;
    }
};

int main() {
    Solution s;
    vector<int> A = {1, 2, 7, 8, 5};
    vector<Interval> queries = {{1, 2}, {0, 4}, {2, 4}};
    auto r = s.intervalMinNumber(A, queries);
    for (auto i : r) cout << i << " "; cout << endl;
    return 0;
}
