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
    long long sum;
    SegmentNode *left, *right;
    SegmentNode(int s, int e, int m, long long sum) : start(s), end(e), mid(m), sum(sum), left(NULL), right(NULL) {}
};

class SegmentTree {
private:
    SegmentNode* root;

    SegmentNode* build(vector<int>& A, int start, int end) {
        if (start == end) return NULL;
        if (start+1 == end) {
            SegmentNode* leaf = new SegmentNode(start, end, start, (long long)A[start]);
            return leaf;
        }
        SegmentNode* root = new SegmentNode(start, end, (start+end)/2, 0l);
        root->left = build(A, start, root->mid);
        root->right = build(A, root->mid, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    long long query(SegmentNode* root, Interval i) {
        if (!root || i.start >= root->end || i.end <= root->start) return -1; // illegal
        if (i.start == root->start && i.end == root->end) return root->sum;
        if (i.end <= root->mid) return query(root->left, i);
        else if (i.start >= root->mid) return query(root->right, i);
        else return query(root->left, Interval(i.start, root->mid)) + query(root->right, Interval(root->mid, i.end));
    }

    void print(SegmentNode* root) {
        if (root) {
            print(root->left);
            cout << root->start << " " << root->end << " " << root->sum << endl;
            print(root->right);
        }
    }

public:
    SegmentTree(vector<int>& A) {
        root = build(A, 0, A.size());
    }

    long long query(Interval i) {
        return query(root, i);
    }
};



class Solution { 
public:
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        if (A.empty() || queries.empty()) return {};
        vector<long long> result;
        SegmentTree st(A);
        for (auto &i : queries) result.push_back(st.query(Interval(i.start, i.end+1)));
        return result;
    }
};

int main() {
    Solution s;
    vector<int> A = {1, 2, 7, 8, 5};
    vector<Interval> queries = {{0, 4}, {1, 2}, {2, 4}};
    auto r = s.intervalSum(A, queries);
    for (auto i : r) cout << i << " "; cout << endl;
    return 0;
}

