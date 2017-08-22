#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Different from 205 and 206, here we build SegmentTree with values(0, 10000), not array indexes

struct SegmentNode { // [start, end)
    int start, end, mid;
    int count = 0;
    SegmentNode *left, *right;
    SegmentNode(int s, int e, int m) : start(s), end(e), mid(m), left(NULL), right(NULL) {}
};

class SegmentTree {
private:
    SegmentNode* root;
    int MAX = 10012; // upper bound

    SegmentNode* build(int start, int end) { // only build trees with count 0
        if (start == end) return NULL;
        if (start+1 == end) {
            SegmentNode* leaf = new SegmentNode(start, end, start);
            return leaf;
        }
        SegmentNode* root = new SegmentNode(start, end, (start+end)/2);
        root->left = build(start, root->mid);
        root->right = build(root->mid, end);
        return root;
    }

    void update(SegmentNode* root, int index, int value) {
        if (!root || index < root->start || index >= root->end) return;
        if (root->start == index && root->end-1 == index) {
            root->count += value; // be careful, it's += rather than =
            return;
        }
        if (index < root->mid) update(root->left, index, value);
        else update(root->right, index, value);
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
    SegmentTree(vector<int>& A) {
        root = build(0, MAX);
        for (int &i : A) update(root, i, 1);
        //print(root);
    }

    int query(int start, int end) {
        return query(root, start, end);
    }
};

class Solution { 
public:
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        if (queries.empty()) return {};
        vector<int> result;
        SegmentTree st(A);
        for (int &i : queries) result.push_back(st.query(0, i));
        return result;
    }
};


int main() {
    Solution s;
    vector<int> A = {1, 2, 7, 8, 5};
    vector<int> queries = {1, 8, 5};
    auto r = s.countOfSmallerNumber(A, queries);
    for (auto i : r) cout << i << " "; cout << endl;
    return 0;
}

